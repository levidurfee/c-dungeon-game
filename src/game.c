/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>
#include "game.h"
#include "player.h"

void game_start(s_room *start, s_player *player)
{
    WINDOW *main;
    int ch;

    if((main = initscr()) == NULL)
    {
        fprintf(stderr, "Error initializing ncurses.\n");
        exit(EXIT_FAILURE);
    }

    noecho();
    keypad(main, TRUE);

    mvaddstr(1, 0, "Where do you wanna go? (n, e, w, s) ('q' to quit)...");
    mvprintw(3, 0, "Location: %s", start->name);
    refresh();

    int moved = 0;

    while((ch = getch()) != 'q') {
        switch(ch) {
            case 110:
                moved = player_move_north(player);
            break;
            case 115:
                moved = player_move_south(player);
            break;
            case 101:
                moved = player_move_east(player);
            break;
            case 119:
                moved = player_move_west(player);
            break;
        }

        deleteln();
        if(moved == 0) {
            mvprintw(2, 0, "You ran into a wall lol.");
        } else {
            mvprintw(2, 0, "");
            deleteln();
        }
        mvprintw(3, 0, "Location: %s", player->room->name);
        refresh();
    }

    delwin(main);
    endwin();
    refresh();
}
