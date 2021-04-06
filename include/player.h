/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "defs.h"

#ifndef _PLAYER_H
#define _PLAYER_H

s_player player_create(char *name, int age, s_room *room);

void player_print(s_player player);

int player_move_north(s_player *player);
int player_move_south(s_player *player);
int player_move_east(s_player *player);
int player_move_west(s_player *player);

int player_move(s_player *player, s_room *from, s_room *to);

#endif /* _PLAYER_H */
