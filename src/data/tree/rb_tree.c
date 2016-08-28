/*
 * redblack_tree.c
 *
 *  Created on: Apr 3, 2016
 *      Author: kiddy
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../common/common.h"
#include "rb_tree.h"

struct rb_node *rb_node_init(void *key, void *value, bool color) {
    struct rb_node *node = malloc(sizeof(struct rb_node));
    node->key = key;
    node->value = value;
    node->color = color;
    node->parent = NULL;
    node->left = NULL;  // nil node
    node->right = NULL; // nil node
    return node;
}

struct rb_node *rb_node_grandpt(struct rb_node *node) {
    if (node->parent == NULL)
        return NULL;
    return node->parent->parent;
}

struct rb_node *rb_node_uncle(struct rb_node *node) {
    struct rb_node *grandparent = rb_node_grandpt(node);
    if (node->parent == NULL || grandparent == NULL)
        return NULL;

    return node->parent == grandparent->left ? grandparent->right : grandparent->left;
}

bool rb_node_is_nil(struct rb_node *node) {
    return node->left == NULL && node->right == NULL;
}

struct rb_tree *rb_tree_init() {
    struct rb_tree *tree = malloc(sizeof(struct rb_tree));
    tree->root = NULL;
    return tree;
}

// SEARCH
struct rb_node *_rb_tree_search(struct rb_node *node, void *key) {
    if (*key == *node->key)
        return node;

    if (*key < *node->key) {
        return _rb_tree_search(node->left, key);
    } else {
        return _rb_tree_search(node->right, key);
    }
}
struct rb_node *rb_tree_search(struct rb_tree *t, void *key) {
    if (t->root == NULL)
        return NULL;

    return _rb_tree_search(t->root, key);
}

//---------------------------------------------
// INSERT
//---------------------------------------------
void _rb_left_rotate(struct rb_node **node) {
    struct rb_node *tmp = *node;
    *node = tmp->right;
    (*node)->left = tmp;
    tmp->right = NULL;
}
void _rb_right_rotate(struct rb_node **node) {
    struct rb_node *tmp = *node;
    *node = tmp->left;
    (*node)->right = tmp;
    tmp->left = NULL;
}
// fix up, until not conflict
void _rb_tree_fixup(struct rb_node **node) {
    if ((*node)->parent->color == BLACK) // nothing to do
        return;

    struct rb_node *uncle = rb_node_uncle(*node);
    if (uncle != NULL && uncle->color == RED) { // check NULL because we not implement NIL
        // color parent and uncle black
        (*node)->parent->color = BLACK;
        uncle->color = BLACK;
        // color grandparent red
        struct rb_node *grandpt = rb_node_grandpt(*node);
        grandpt->color = RED;
        if (grandpt->parent == NULL) { // grandpt is root
            // just color the root black and done!
            grandpt->color = BLACK;
            return;
        }
        // treat grandpt as new RED node and fix up
        _rb_tree_fixup(&grandpt);
    } else { // uncle->color == BLACK, this only happen when uncle is a leaf
        // see https://upload.wikimedia.org/wikipedia/commons/thumb/6/66/Red-black_tree_example.svg/750px-Red-black_tree_example.svg.png
        if ((*node) == (*node)->parent->right) {
            (*node)->parent->color = BLACK;
            rb_node_grandpt(*node)->color = RED;
            _rb_left_rotate(&rb_node_grandpt(*node));
        } else {
            struct rb_node *grandpt = rb_node_grandpt(*node);
            (*node)->color = RED;
            grandpt->color = RED;
            _rb_right_rotate(&(*node)->parent);
            _rb_left_rotate(&grandpt);
        }
    }
}
bool _rb_tree_insert(struct rb_node **subroot, struct rb_node *newnode) {
    if (*subroot == NULL) {
        *subroot = newnode;
        return true;
    }

    if (*newnode->key == *(*subroot)->key)
        return false;

    if (*newnode->key < *(*subroot)->key) {
        return _rb_tree_insert((*subroot)->left, newnode);
    } else {
        return _rb_tree_insert((*subroot)->right, newnode);
    }
}
bool rb_tree_insert(struct rb_tree *t, void *key, void *value) {
    struct rb_node *newnode = rb_node_init(key, value, RED);
    bool result = _rb_tree_insert(&t->root, newnode);
    _rb_tree_fixup(newnode);
    return result;
}
// --- END INSERT
