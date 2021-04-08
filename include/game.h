/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "node.h"
#include "player.h"

#ifndef _GAME_H
#define _GAME_H

typedef struct game {
    struct node *map;
    s_player    *player;
} s_game;

void game_start(char *filename, char *player_name);

#endif /* _GAME_H */
