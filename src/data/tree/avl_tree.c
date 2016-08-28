/*
 * alv_tree.c
 *
 *  Created on: Apr 3, 2016
 *      Author: kiddy
 */

#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

struct avl_node *node_init(int data) {
    struct avl_node *n = malloc(sizeof(struct avl_node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->balancer = 0;
    return n;
}

struct avl_tree *tree_init() {
    struct avl_tree *t = malloc(sizeof(struct avl_tree));
    t->root = NULL;
    t->size = 0;
    return t;
}

void left_rotate(struct avl_node **node) {
    struct avl_node *_node = *node;
    if (_node->left->balancer == 1) {
        *node = _node->left;
        (*node)->right = _node;
        _node->left = _node->right = NULL;
    } else if (_node->left->balancer == -1) {
        *node = _node->left->right;
        (*node)->left = _node->left;
        (*node)->right = _node;
        (*node)->left->right = NULL;
        _node->left = _node->right = NULL;
    }
}
bool _tree_insert_recur(struct avl_node **subroot, int data, bool *taller) {
    if (*subroot == NULL) {
        *subroot = node_init(data);
        *taller = true;
        return true;
    }

    int nodedata = (*subroot)->data;
    if (data == nodedata)
        return false;

    if (data < nodedata) {  // insert left subtree
        _tree_insert_recur(&(*subroot)->left, data, taller);
        if (*taller) {
            struct avl_node *_node = *subroot; // ?? WHY THIS CANNOT IN "case"
            switch (_node->balancer) {
            case -1:    // left < right
                _node->balancer = 0;
                *taller = false;
                break;
            case 0:     // left = right
                _node->balancer = 1;
                break;
            case 1:     // left > right: rotate
                left_rotate(subroot);
                _node->balancer = 0;
                taller = false;
                break;
            }
        }
    } else {    // insert right subtree
        _tree_insert_recur(&(*subroot)->right, data, taller);
        if (*taller) {
            switch ((*subroot)->balancer) {
            case 1:     // left > right
                (*subroot)->balancer = 0;
                *taller = false;
                break;
            case 0:     // left = right
                (*subroot)->balancer = -1;
                break;
            case -1:    // left < right
                // TODO rotate
                break;
            }
        }
    }

    return true;
}
bool tree_insert(struct avl_tree *t, int data) {
    if (t == NULL)
        return false;

    bool taller = false;
    return _tree_insert_recur(&t->root, data, &taller);
}

/** depth first L-N-R traversal with recursion */
void _tree_inorder_traverse_recur(struct avl_node *node, void(*op)(struct avl_node *node)) {
    if (node == NULL)
        return;

    _tree_inorder_traverse_recur(node->left, op);
    (*op)(node);
    _tree_inorder_traverse_recur(node->right, op);
}
void tree_inorder_traverse(struct avl_tree *t, void(*op)(struct avl_node *avl_node)) {    // LNR
    if (t == NULL && t->root == NULL)
        return;

    _tree_inorder_traverse_recur(t->root, op);
}
int _tree_height_recur(struct avl_node *node) {
    if (node == NULL)
        return 0;

    int left_height = _tree_height_recur(node->left);
    int right_height = _tree_height_recur(node->right);
    return left_height > right_height ? left_height+1 : right_height+1;
}
int tree_height(struct avl_tree *t) {
    if (t == NULL)
        return -1;

    return _tree_height_recur(t->root);
}
