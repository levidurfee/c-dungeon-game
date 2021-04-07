/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "defs.h"

#ifndef _ROOM_H
#define _ROOM_H

/**
 * room_create - creates a new room with the name specified.
 */
s_room *room_create(int id, char *name);

/**
 * room_free - will free the malloc.
 */
void room_free(s_room *room);

/**
 * room_list_init - creates a new linked list for building the map.
 */
s_room_list *room_list_init();

void room_list_insert(s_room_list **head, s_room *room);
void room_list_print(s_room_list **head);

/**
 * room_list_free - will free the malloc.
 */
void room_list_free(s_room_list *room);

s_room *room_map_load(char *map, char *rooms);

#endif /* _ROOM_H */
