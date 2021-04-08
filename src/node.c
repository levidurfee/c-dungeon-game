/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <malloc.h>
#include "node.h"

struct node *node_new(s_room *room)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->room = room;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node *node_insert(struct node *node, s_room *room)
{
    if(node == NULL) {
        return node_new(room);
    }

    if(room->id < node->room->id) {
        node->left = node_insert(node->left, room);
    } else {
        node->right = node_insert(node->right, room);
    }

    return node;
}

struct node *node_delete(struct node *root, int id)
{
    if(root == NULL) {
        return root;
    }

    // If the room ID to be deleted is smaller than the root's room ID, then the
    // room is in the left subtree.
    if(id < root->room->id) {
        root->left = node_delete(root->left, id);

    // If the room ID to be deleted is greater than the root's room ID, then the
    // room is in the right subtree.
    } else if(id > root->room->id) {
        root->right = node_delete(root->right, id);

    // If the room ID is the same as the root's room ID, then this is the node
    // to be deleted.
    } else {
        if(root->left == NULL) {
            struct node *temp = root->right;
            room_free(root->room);
            free(root);

            return temp;
        } else if(root->right == NULL) {
            struct node *temp = root->left;
            room_free(root->room);
            free(root);

            return temp;
        }

        // Node with two children, get inorder successor (smallest in the right
        // subtree)
        struct node *temp = node_min_value(root->right);

        // Copy inorder successor's room to this node.
        root->room = temp->room;

        root->right = node_delete(root->right, temp->room->id);
    }

    return root;
}

struct node *node_min_value(struct node *node)
{
    struct node *current = node;

    while(current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct node *node_search(struct node *root, int id)
{
    if(root == NULL || root->room->id == id) {
        return root;
    }

    if(root->room->id < id) {
        return node_search(root->right, id);
    }

    return node_search(root->left, id);
}

void node_destroy(struct node *root)
{
    if(root == NULL) {
        return;
    }

    node_destroy(root->left);
    node_destroy(root->right);

    free(root->room->name);
    free(root->room);
    free(root);
}

void node_inorder(struct node *root)
{
    if(root != NULL) {
        node_inorder(root->left);
        printf("%d\t%d\t%s\n", root->room->id, root->room->north, root->room->name);
        node_inorder(root->right);
    }
}
