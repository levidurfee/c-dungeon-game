/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "defs.h"

#ifndef _PLAYER_H
#define _PLAYER_H

s_player player_create(char *name, int age, s_room *room);

void player_print(s_player player);

#endif /* _PLAYER_H */
