/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include "room.h"

s_room room_create(char *name)
{
    s_room room;
    room.name  = name;
    room.east  = NULL;
    room.west  = NULL;
    room.north = NULL;
    room.south = NULL;

    return room;
}
