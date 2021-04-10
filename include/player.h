/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#ifndef _PLAYER_H
#define _PLAYER_H

typedef struct player {
    char *name;
} s_player;

/**
 * Create a new player with the name specified.
 */
s_player *player_new(char *name);

/**
 * Free the player pointer.
 */
void player_free(s_player *player);

#endif /* _PLAYER_H */
