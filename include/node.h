/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include "room.h"

#ifndef _NODE_H
#define _NODE_H

typedef struct node {
    s_room *room;

    struct node *left;
    struct node *right;
} s_node;

struct node *node_new(s_room *room);

struct node *node_insert(struct node *node, s_room *room);

struct node *node_delete(struct node *root, int id);

struct node *node_min_value(struct node *node);

struct node *node_search(struct node *root, int id);

void node_destroy(struct node *root);

void node_inorder(struct node *root);

#endif /* _NODE_H */
