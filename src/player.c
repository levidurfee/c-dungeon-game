/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <malloc.h>
#include "player.h"

s_player *player_new(char *name)
{
    s_player *player = (s_player *)malloc(sizeof(s_player));
    player->name = name;

    return player;
}

void player_free(s_player *player)
{
    free(player);
}
