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

void game_start(char *filename, char *player_name)
{
    WINDOW *main;
    int ch;

    struct node *map = map_load(filename);
    s_player *player = player_new(player_name);

    s_game *game = (s_game *)malloc(sizeof(s_game));
    game->map = map;
    game->player = player;

    if((main = initscr()) == NULL)
    {
        fprintf(stderr, "ncurses error\n");
        exit(EXIT_FAILURE);
    }
    noecho();
    keypad(main, TRUE);

    mvaddstr(1, 0, "Where do you wanna go? (n, e, w, s) ('q' to quit)...");

    struct node *node = node_search(map, 1);
    s_room *current_room = node->room;
    mvprintw(3, 0, "%s", current_room->name);

    refresh();

    while((ch = getch()) != 'q') {
        switch(ch) {
            case 110:
                if(current_room->north == 0) {
                    mvprintw(4, 0, "Can't go north!");
                    break;
                }
                node = node_search(map, current_room->north);
                current_room = node->room;
                mvprintw(2, 0, "north");
            break;
            case 115:
                if(current_room->south == 0) {
                    mvprintw(4, 0, "Can't go south!");
                    break;
                }
                node = node_search(map, current_room->south);
                current_room = node->room;
                mvprintw(2, 0, "south");
            break;
            case 101:
                if(current_room->east == 0) {
                    mvprintw(4, 0, "Can't go east!");
                    break;
                }
                node = node_search(map, current_room->east);
                current_room = node->room;
                mvprintw(2, 0, "east");
            break;
            case 119:
                if(current_room->west == 0) {
                    mvprintw(4, 0, "Can't go west!");
                    break;
                }
                node = node_search(map, current_room->west);
                current_room = node->room;
                mvprintw(2, 0, "west");
            break;
        }
        mvprintw(3, 0, "%s", current_room->name);
        refresh();
    }

    delwin(main);
    endwin();
    refresh();

    node_destroy(map);
    player_free(player);
    free(game);
}
