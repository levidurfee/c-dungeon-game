/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "room.h"

#define MAX_STR_LEN 60

s_room *room_create(int id, char *name)
{
    s_room *room = (s_room *)malloc(sizeof(s_room));
    room->id    = id;
    room->name  = name;
    room->east  = NULL;
    room->west  = NULL;
    room->north = NULL;
    room->south = NULL;

    return room;
}

void room_free(s_room *room)
{
    free(room);
}

s_room_list *room_list_init()
{
    s_room_list *self = (s_room_list *)malloc(sizeof(s_room_list));

    self->next = NULL;
    self->room = NULL;

    return self;
}

void room_list_insert(s_room_list **head, s_room *room)
{
    s_room_list *current = *head;
    s_room_list *tmp;

    do {
        tmp = current;
        current = current->next;
    } while(current);

    s_room_list *new = room_list_init();
    tmp->room = room;
    tmp->next = new;
}

void room_list_print(s_room_list **head)
{
    s_room_list *current = *head;
    while(current) {
        if(current->room == NULL) {
            break;
        }
        printf("%p\tid:%d\tname:%s\n", current->room, current->room->id, current->room->name);
        current = current->next;
    }
}

s_room *room_list_search(s_room_list **head, int id)
{
    s_room_list *current = *head;
    while(current) {
        if(current->room == NULL) {
            break;
        }
        if(current->room->id == id) {
            return current->room;
        }
        current = current->next;
    }

    return NULL;
}

void room_list_free(s_room_list *room)
{
    free(room);
}

s_room *room_map_load(char *map_file, char *rooms_file)
{
    // Go ahead and create the data structure we actually want to return before
    // we do anything else, I like doing it this way because I think it's clear.
    s_room *map_list = (s_room *)malloc(sizeof(s_room));

    // Use a linked-list to help create our actual map structure. Each room will
    // get an ID, then we can link the rooms together by finding that room using
    // it's ID. So, we will make calls to room_list_init() and room_list_free().
    s_room_list *rooms_list = room_list_init();

    // Prepare for loading, reading, and parsing the TSV file.
    char line[MAX_STR_LEN];
    FILE *fp = fopen(rooms_file, "r");
    while(1) {
        if(fgets(line, MAX_STR_LEN, fp) == NULL) {
            break;
        }

        char *token = strtok(line, "\t");
        int id = atoi(token);

        char *name = strtok(NULL, "\t");
        name[strcspn(name, "\n")] = 0;
        char *tmp = strdup(name);

        s_room *new_room = room_create(id, tmp);
        room_list_insert(&rooms_list, new_room);
    }
    fclose(fp);

    // Debug only
    // room_list_print(&rooms_list);

    int x = 0;
    FILE *mfp = fopen(map_file, "r");
    while(1) {
        if(fgets(line, MAX_STR_LEN, mfp) == NULL) {
            break;
        }

        // We wanna skip the first line
        if(x == 0) {
            x++;
            continue;
        }

        int id;
        char *token;

        // Now we gotta find each room by the ID. Then, if any of the below are
        // not 0, we find the room by that ID and link the rooms.
        token = strtok(line, "\t");
        id = atoi(token);
        s_room *base = room_list_search(&rooms_list, id);

        // North, if not 0, find room, and set room's north to this room.
        token = strtok(NULL, "\t");
        id = atoi(token);
        if(id != 0) {
            s_room *north = room_list_search(&rooms_list, id);
            base->north = north;
        }

        // South
        token = strtok(NULL, "\t");
        id = atoi(token);
        if(id != 0) {
            s_room *south = room_list_search(&rooms_list, id);
            base->south = south;
        }

        // West
        token = strtok(NULL, "\t");
        id = atoi(token);
        if(id != 0) {
            s_room *west = room_list_search(&rooms_list, id);
            base->west = west;
        }

        // East
        token = strtok(NULL, "\t");
        id = atoi(token);
        if(id != 0) {
            s_room *east = room_list_search(&rooms_list, id);
            base->east = east;
        }
    }
    fclose(mfp);

    // As mentioned above, we're only using the linked-list to help build our
    // actual data structure for the rooms. So, we can free the linked list
    // while in this function and don't have to worry about it elsewhere.
    room_list_free(rooms_list);

    // Since we created the data structure at the beginning of this function, I
    // know we can return it.
    return map_list;
}
