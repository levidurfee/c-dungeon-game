/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include "player.h"

s_player player_create(char *name, int age, s_room *room)
{
    s_player player;
    player.name = name;
    player.age  = age;
    player.room = room;

    return player;
}

void player_print(s_player player)
{
    printf("%s is in the %s\n", player.name, player.room->name);
}

int player_move_north(s_player *player)
{
    if(player->room->north != NULL) {
        // Since the player and the room both point to each other, we need to
        // update both variables with their new values. The player is now in
        // the north room. And the north room now contains the player.
        return player_move(player, player->room, player->room->north);
    }

    return 0;
}

int player_move_south(s_player *player)
{
    if(player->room->south != NULL) {
        // Since the player and the room both point to each other, we need to
        // update both variables with their new values. The player is now in
        // the south room. And the south room now contains the player.
        return player_move(player, player->room, player->room->south);
    }

    return 0;
}

int player_move_east(s_player *player)
{
    if(player->room->east != NULL) {
        // Since the player and the room both point to each other, we need to
        // update both variables with their new values. The player is now in
        // the east room. And the east room now contains the player.
        return player_move(player, player->room, player->room->east);
    }

    return 0;
}

int player_move_west(s_player *player)
{
    if(player->room->west != NULL) {
        // Since the player and the room both point to each other, we need to
        // update both variables with their new values. The player is now in
        // the west room. And the west room now contains the player.
        return player_move(player, player->room, player->room->west);
    }

    return 0;
}

int player_move(s_player *player, s_room *from, s_room *to)
{
    from->player = NULL;
    to->player = player;

    player->room = to;

    return 1;
}
