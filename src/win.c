/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "win.h"
#include "room.h"

#define WINDOW_TOP_HEIGHT 4
#define WINDOW_BOT_HEIGHT 3

static WINDOW *w_top;
static WINDOW *w_left;
static WINDOW *w_right;
static WINDOW *w_bot;

static void win_print(WINDOW *win, char *msg);
static void win_init_windows();

void win_init()
{
    initscr();
    cbreak();
    noecho();

    w_top   = newwin(WINDOW_TOP_HEIGHT, COLS, 0, 0);
    w_left  = newwin(LINES-(WINDOW_TOP_HEIGHT+WINDOW_BOT_HEIGHT), COLS/2, WINDOW_TOP_HEIGHT, 0);
    w_right = newwin(LINES-(WINDOW_TOP_HEIGHT+WINDOW_BOT_HEIGHT), COLS/2, WINDOW_TOP_HEIGHT, COLS/2);
    w_bot   = newwin(WINDOW_BOT_HEIGHT, COLS, LINES-WINDOW_BOT_HEIGHT, 0);

    refresh();

    win_init_windows();

    mvwprintw(w_top, 1, 2, "What do you wanna do?");
    mvwprintw(w_top, 2, 2, "Move: a, w, s, d Quit: q");

    win_refresh();
}

static void win_init_windows()
{
    box(w_top,   0, 0);
    box(w_left,  0, 0);
    box(w_right, 0, 0);
    box(w_bot,   0, 0);

    mvwprintw(w_top,   0, 2, "Instructions");
    mvwprintw(w_left,  0, 2, "Description");
    mvwprintw(w_right, 0, 2, "Map");
    mvwprintw(w_bot,   0, 2, "Status");
}

void win_desc(char *name)
{
    werase(w_left);
    win_init_windows();

    win_print(w_left, name);
}

void win_status(char *msg)
{
    win_print(w_bot, msg);
}

void win_map(s_room *room)
{
    werase(w_right);
    win_init_windows();

    // Figure out coordinates
    int offset = 0;
    int x_middle = COLS/2/2;
    int y_middle = (LINES-(WINDOW_TOP_HEIGHT+WINDOW_BOT_HEIGHT)) / 2;

    offset = strlen(room->north_name) / 2;
    mvwprintw(w_right, 1, x_middle-offset, room->north_name);

    mvwprintw(w_right, y_middle, 2, room->west_name);

    offset = strlen(room->name) / 2;
    mvwprintw(w_right, y_middle, x_middle-offset, room->name);

    offset = (COLS/2) - (strlen(room->east_name) + 2);
    mvwprintw(w_right, y_middle, offset, room->east_name);

    offset = strlen(room->south_name) / 2;
    int bottom = LINES-(WINDOW_TOP_HEIGHT+WINDOW_BOT_HEIGHT) - 2;
    mvwprintw(w_right, bottom, x_middle-offset, room->south_name);

    win_refresh();
}

static void win_print(WINDOW *win, char *msg)
{
    mvwprintw(win, 1, 2, msg);

    win_refresh();
}

void win_end()
{
    delwin(w_top);
    delwin(w_left);
    delwin(w_right);
    delwin(w_bot);

    endwin();
}

void win_refresh()
{
    wrefresh(w_top);
    wrefresh(w_left);
    wrefresh(w_right);
    wrefresh(w_bot);
}
