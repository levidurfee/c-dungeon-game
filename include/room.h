/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#ifndef _ROOM_H
#define _ROOM_H

typedef struct room {
    int id;

    char *name;

    int north;
    int west;
    int east;
    int south;

    char *description;

    char *north_name;
    char *west_name;
    char *east_name;
    char *south_name;
} s_room;

/**
 * Create a new s_room using the ID and name provided.
 */
s_room *room_new(int id);

void room_free(s_room *room);

#endif /* _ROOM_H */
