/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include <ncurses.h>
#include "game.h"
#include "player.h"

void game_start(s_room *start, s_player *player)
{
    int c;

    printf("Welcome to %s\n", start->name);

    for(;;) {
        printf("%s enters the %s\n", player->name, player->room->name);
        printf("Where would you like to go? (n, e, w, s) (q to quit)\n");

        c = getchar();

        switch (c)
        {
        case 110:
            if(!player_north(player)) {
                printf("Door is locked!\n");
            }
            break;

        case 113:
            printf("You got too scared and left.\n");
            return;
            break;
        default:
            break;
        }
    }
}
