/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include "player.h"

s_player player_create(char *name, int age, s_room *room)
{
    s_player player;
    player.name = name;
    player.age  = age;
    player.room = room;

    return player;
}

void player_print(s_player player)
{
    printf("%s is in the %s\n", player.name, player.room->name);
}
