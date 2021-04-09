/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "node.h"

#ifndef _MAP_H
#define _MAP_H

/**
 * Load a map from the specified filename.
 */
struct node *map_load(char *filename);

#endif /* _MAP_H */
