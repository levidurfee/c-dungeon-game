/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "map.h"
#include "node.h"
#include "room.h"

#define SEPARATOR "^"
#define MAX_STR_LEN 100

static s_room *parse_line(char *line);

struct node *map_load(char *filename)
{
    struct node *map;

    int x = 0;
    char line[MAX_STR_LEN];
    FILE *fp = fopen(filename, "r");
    while(1) {
        if(fgets(line, MAX_STR_LEN, fp) == NULL) {
            break;
        }

        // Skip the header.
        if(x == 0) {
            x++;

            continue;
        }

        // First room will be used to start the binary search tree.
        if(x == 1) {
            x++;
            s_room *start = parse_line(line);
            map = node_new(start);

            continue;
        }

        // Now we just create rooms and add them to our map.
        s_room *room = parse_line(line);
        node_insert(map, room);

        x++;
    }
    fclose(fp);

    return map;
}

static s_room *parse_line(char *line)
{
    char *token;

    // ID
    token     = strtok(line, SEPARATOR);
    int id    = atoi(token);

    // North
    token     = strtok(NULL, SEPARATOR);
    int north = atoi(token);

    // South
    token     = strtok(NULL, SEPARATOR);
    int south = atoi(token);

    // West
    token    = strtok(NULL, SEPARATOR);
    int west = atoi(token);

    // East
    token    = strtok(NULL, SEPARATOR);
    int east = atoi(token);

    // Name
    char *name = strtok(NULL, SEPARATOR);
    // name[strcspn(name, "\n")] = 0;
    char *tmp = strdup(name);

    char *msg = strtok(NULL, SEPARATOR);
    msg[strcspn(msg, "\n")] = 0;
    char *desc = strdup(msg);

    s_room *room = room_new(id, tmp);
    room->north = north;
    room->south = south;
    room->west  = west;
    room->east  = east;

    room->description = desc;

    return room;
}
