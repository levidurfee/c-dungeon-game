/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "room.h"

int main()
{
	s_room *map = room_map_load("files/map.tsv", "files/rooms.tsv");

	room_free(map);

	return (0);
}
