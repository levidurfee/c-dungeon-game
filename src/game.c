/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>

#include "db.h"
#include "map.h"
#include "win.h"
#include "game.h"
#include "node.h"
#include "player.h"

#define WINDOW_TOP_HEIGHT 4
#define WINDOW_BOT_HEIGHT 4

void game_start(char *player_name)
{
    int ch;

    db_init();
    struct node *map = map_get();
    s_player *player = player_new(player_name);

    s_game *game = (s_game *)malloc(sizeof(s_game));
    game->map    = map;
    game->player = player;

    win_init();

    struct node *node = node_search(map, 1);
    s_room *current_room = node->room;
    win_desc(current_room->description);

    s_room *cr = node_search_map(map, current_room->id);
    win_map(cr);

    while((ch = getch()) != 'q') {
        switch(ch) {
            case 'w':
            case 65:
                if(current_room->north == 0) {
                    win_status("");
                    break;
                }
                node = node_search(map, current_room->north);
                current_room = node->room;
            break;
            case 's':
            case 66:
                if(current_room->south == 0) {
                    win_status("");
                    break;
                }
                node = node_search(map, current_room->south);
                current_room = node->room;
            break;
            case 'd':
            case 67:
                if(current_room->east == 0) {
                    win_status("");
                    break;
                }
                node = node_search(map, current_room->east);
                current_room = node->room;
            break;
            case 'a':
            case 68:
                if(current_room->west == 0) {
                    win_status("");
                    break;
                }
                node = node_search(map, current_room->west);
                current_room = node->room;
            break;
        }
        cr = node_search_map(map, current_room->id);
        win_map(cr);
        win_desc(current_room->description);
    }

    win_end();
    node_destroy(map);
    player_free(player);
    free(game);
}
