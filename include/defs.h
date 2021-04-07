/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#ifndef _DEFS_H
#define _DEFS_H

typedef struct player s_player;
typedef struct room s_room;

struct player
{
    char   *name;
    int    age;

    s_room *room;
};

struct room
{
    int         id;
    char        *name;
    struct room *north;
    struct room *east;
    struct room *west;
    struct room *south;

    s_player    *player;
};

typedef struct room_list
{
    struct room_list *next;
    s_room           *room;
} s_room_list;

#endif /* _DEFS_H */
