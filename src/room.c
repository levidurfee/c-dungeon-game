/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <malloc.h>
#include "room.h"

s_room *room_new(int id, char *name)
{
    s_room *room = (s_room *)malloc(sizeof(s_room));

    room->id    = id;
    room->name  = name;
    room->north = 0;
    room->west  = 0;
    room->east  = 0;
    room->south = 0;

    return room;
}

void room_free(s_room *room)
{
    free(room);
}
