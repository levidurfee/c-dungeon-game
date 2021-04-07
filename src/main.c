/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "room.h"

int main()
{
	s_room_list *rooms = room_list_init();

	s_room *entrance = room_create("Entrance");
	rooms->room = entrance;

	room_free(entrance);
	room_list_free(rooms);

	return (0);
}
