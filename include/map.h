/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "node.h"

#ifndef _MAP_H
#define _MAP_H

struct node *map_get();

/**
 */
int map_load(void *not_used, int argc, char **argv, char **col_name);

#endif /* _MAP_H */
