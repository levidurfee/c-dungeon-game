/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

#include "map.h"
#include "win.h"
#include "game.h"
#include "node.h"
#include "player.h"

#define WINDOW_TOP_HEIGHT 4
#define WINDOW_BOT_HEIGHT 4

void game_start(char *filename, char *player_name)
{
    int ch;

    struct node *map = map_load(filename);
    s_player *player = player_new(player_name);

    s_game *game = (s_game *)malloc(sizeof(s_game));
    game->map = map;
    game->player = player;

    win_init();

    struct node *node = node_search(map, 1);
    s_room *current_room = node->room;
    win_location(current_room->name);

    while((ch = getch()) != 'q') {
        switch(ch) {
            case 110:
                if(current_room->north == 0) {
                    win_status("Can't go north!");
                    break;
                }
                node = node_search(map, current_room->north);
                current_room = node->room;
            break;
            case 115:
                if(current_room->south == 0) {
                    win_status("Can't go south!");
                    break;
                }
                node = node_search(map, current_room->south);
                current_room = node->room;
            break;
            case 101:
                if(current_room->east == 0) {
                    win_status("Can't go east!");
                    break;
                }
                node = node_search(map, current_room->east);
                current_room = node->room;
            break;
            case 119:
                if(current_room->west == 0) {
                    win_status("Can't go west!");
                    break;
                }
                node = node_search(map, current_room->west);
                current_room = node->room;
            break;
        }
        win_location(current_room->name);
    }

    win_end();
    node_destroy(map);
    player_free(player);
    free(game);
}
