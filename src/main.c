/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "game.h"
#include "room.h"
#include "player.h"

int main()
{
	s_room room_start = room_create("haunted house");
	s_player levi = player_create("Levi", 36, &room_start);

	s_room murder = room_create("murder room");
	room_start.north = &murder;
	murder.south = &room_start;

	s_room kitchen = room_create("kitchen");
	murder.east = &kitchen;
	kitchen.west = &murder;

	game_start(&room_start, &levi);

	return (0);
}
