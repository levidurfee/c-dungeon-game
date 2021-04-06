/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "room.h"
#include "player.h"

int main()
{
	s_room room_start = room_create("Entranace");
	s_player levi = player_create("Levi", 36, &room_start);

	player_print(levi);

	return (0);
}
