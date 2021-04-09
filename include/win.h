/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

/**
 * Initialize ncurses and build our windows.
 */
void win_init();

/**
 * Update the text for the window that contains the player's location.
 */
void win_location(char *name);

/**
 * Update the text for the window that contains the player's status.
 */
void win_status(char *name);

/**
 * Free up ncurses pointers and etc.
 */
void win_end();

/**
 * Refresh all of the windows.
 */
void win_refresh();
