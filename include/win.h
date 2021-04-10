/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "room.h"

#ifndef _WIN_H
#define _WIN_H

/**
 * Initialize ncurses and build our windows.
 */
void win_init();

/**
 * Update the text for the current room.
 */
void win_desc(char *name);

/**
 * Update the text for the window that contains the player's status.
 */
void win_status(char *name);

/**
 * Update the map.
 */
void win_map(s_room *room);

/**
 * Free up ncurses pointers and etc.
 */
void win_end();

/**
 * Refresh all of the windows.
 */
void win_refresh();

#endif /* _WIN_H */
