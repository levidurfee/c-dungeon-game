/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

#include "win.h"

#define WINDOW_TOP_HEIGHT 4
#define WINDOW_BOT_HEIGHT 3

static WINDOW *w_top;
static WINDOW *w_left;
static WINDOW *w_right;
static WINDOW *w_bot;

static void win_print(WINDOW *win, char *msg);

void win_init()
{
    initscr();
    cbreak();
    noecho();

    w_top = newwin(WINDOW_TOP_HEIGHT, COLS, 0, 0);
    w_left = newwin(LINES-(WINDOW_TOP_HEIGHT+WINDOW_BOT_HEIGHT), COLS/2, WINDOW_TOP_HEIGHT, 0);
    w_right = newwin(LINES-(WINDOW_TOP_HEIGHT+WINDOW_BOT_HEIGHT), COLS/2, WINDOW_TOP_HEIGHT, COLS/2);
    w_bot = newwin(WINDOW_BOT_HEIGHT, COLS, LINES-WINDOW_BOT_HEIGHT, 0);

    refresh();

    box(w_top, 0, 0);
    box(w_left, 0, 0);
    box(w_right, 0, 0);
    box(w_bot, 0, 0);

    mvwprintw(w_top, 0, 2, "Instructions");
    mvwprintw(w_left, 0, 2, "Status");
    mvwprintw(w_right, 0, 2, "Map");
    mvwprintw(w_bot, 0, 2, "Status");

    mvwprintw(w_top, 1, 2, "What do you wanna do?");
    mvwprintw(w_top, 2, 2, "Move: n, w, e, s Quit: q");

    win_refresh();
}

void win_location(char *name)
{
    win_print(w_left, name);
}

void win_status(char *msg)
{
    win_print(w_bot, msg);
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
