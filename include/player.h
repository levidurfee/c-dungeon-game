/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#ifndef _PLAYER_H
#define _PLAYER_H

typedef struct player {
    char *name;
} s_player;

s_player *player_new(char *name);

void player_free(s_player *player);

#endif /* _PLAYER_H */
