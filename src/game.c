/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

#include "map.h"
#include "game.h"
#include "node.h"
#include "player.h"

#define WINDOW_TOP_HEIGHT 4

void game_start(char *filename, char *player_name)
{
    int ch;

    struct node *map = map_load(filename);
    s_player *player = player_new(player_name);

    s_game *game = (s_game *)malloc(sizeof(s_game));
    game->map = map;
    game->player = player;

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

    mvwprintw(top_w, 1, 2, "What do you wanna do?");
    mvwprintw(top_w, 2, 2, "Move: n, w, e, s Quite: q");

    wrefresh(top_w);
    wrefresh(left_w);
    wrefresh(right_w);

    struct node *node = node_search(map, 1);
    s_room *current_room = node->room;
    mvwprintw(left_w, 3, 0, "%s", current_room->name);

    wrefresh(top_w);
    wrefresh(left_w);
    wrefresh(right_w);

    while((ch = getch()) != 'q') {
        switch(ch) {
            case 110:
                if(current_room->north == 0) {
                    mvwprintw(left_w, 4, 0, "Can't go north!");
                    break;
                }
                node = node_search(map, current_room->north);
                current_room = node->room;
                mvwprintw(left_w, 2, 0, "north");
            break;
            case 115:
                if(current_room->south == 0) {
                    mvwprintw(left_w, 4, 0, "Can't go south!");
                    break;
                }
                node = node_search(map, current_room->south);
                current_room = node->room;
                mvwprintw(left_w, 2, 0, "south");
            break;
            case 101:
                if(current_room->east == 0) {
                    mvwprintw(left_w, 4, 0, "Can't go east!");
                    break;
                }
                node = node_search(map, current_room->east);
                current_room = node->room;
                mvwprintw(left_w, 2, 0, "east");
            break;
            case 119:
                if(current_room->west == 0) {
                    mvwprintw(left_w, 4, 0, "Can't go west!");
                    break;
                }
                node = node_search(map, current_room->west);
                current_room = node->room;
                mvwprintw(left_w, 2, 0, "west");
            break;
        }
        mvwprintw(left_w, 3, 0, "%s", current_room->name);
        wrefresh(top_w);
        wrefresh(left_w);
        wrefresh(right_w);
    }

    delwin(top_w);
    delwin(left_w);
    delwin(right_w);

    endwin();

    node_destroy(map);
    player_free(player);
    free(game);
}
