/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <ncurses.h>

#define WINDOW_TOP_HEIGHT 4

int main()
{
    initscr();
    cbreak();
    noecho();

    WINDOW *top_w = newwin(WINDOW_TOP_HEIGHT, COLS, 0, 0);
    WINDOW *left_w = newwin(LINES-WINDOW_TOP_HEIGHT, COLS/2, WINDOW_TOP_HEIGHT, 0);
    WINDOW *right_w = newwin(LINES-WINDOW_TOP_HEIGHT, COLS/2, WINDOW_TOP_HEIGHT, COLS/2);

    refresh();

    box(top_w, 0, 0);
    box(left_w, 0, 0);
    box(right_w, 0, 0);

    mvwprintw(top_w, 0, 2, "Instructions");
    mvwprintw(left_w, 0, 2, "Status");
    mvwprintw(right_w, 0, 2, "Map");

    mvwprintw(left_w, 2, 2, "%d %d", LINES, COLS);

    wrefresh(top_w);
    wrefresh(left_w);
    wrefresh(right_w);

    getch();

    delwin(top_w);
    delwin(left_w);
    delwin(right_w);

    endwin();

    return 0;
}
