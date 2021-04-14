/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include "map.h"
#include "node.h"
#include "room.h"
#include "common.h"

#define SEPARATOR "^"
#define MAX_STR_LEN 100

struct node *map = NULL;

int ROW_FLAG = 0;

struct node *map_get()
{
    return map;
}

/**
 * This callback function is called for each row.
 */
int map_load(void *not_used, int argc, char **argv, char **col_name)
{
    UNUSED(not_used);

    s_room *room;
    for (int i = 0; i < argc; i++)
    {
        if(strcmp(col_name[i], "id") == 0) {
            int id = atoi(argv[i]);
            room = room_new(id);
        }

        if(strcmp(col_name[i], "name") == 0) {
            room->name = strdup(argv[i]);
        }

        if(strcmp(col_name[i], "description") == 0) {
            room->description = strdup(argv[i]);
        }

        if(strcmp(col_name[i], "north") == 0) {
            room->north = atoi(argv[i]);
        }

        if(strcmp(col_name[i], "west") == 0) {
            room->west = atoi(argv[i]);
        }

        if(strcmp(col_name[i], "east") == 0) {
            room->east = atoi(argv[i]);
        }

        if(strcmp(col_name[i], "south") == 0) {
            room->south = atoi(argv[i]);
        }
    }

    // If this is the first row
    if(ROW_FLAG == 0) {
        map = node_new(room);
    } else {
        node_insert(map, room);
    }

    ROW_FLAG++;

    return 0;
}
