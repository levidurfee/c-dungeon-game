/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include <malloc.h>
#include "room.h"

s_room *room_create(char *name)
{
    s_room *room = (s_room *)malloc(sizeof(s_room));
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

void room_list_free(s_room_list *room)
{
    free(room);
}
