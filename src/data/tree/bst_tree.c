/*
 * tree.c
 *
 *  Created on: Mar 22, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <stdlib.h>

#include "bst_tree.h"
#include "../queue.h"

struct bst_node *node_init(int data) {
    struct bst_node *n = malloc(sizeof(struct bst_node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct bst_tree *tree_init() {
    struct bst_tree *t = malloc(sizeof(struct bst_tree));
    t->root = NULL;
    t->size = 0;
    return t;
}

size_t tree_size(struct bst_tree *t) {
    return t->size;
}

bool tree_is_empty(struct bst_tree *t) {
    return t->size == 0;
}

void tree_print(struct bst_tree *t) {

}

/**
 * Search a key without recursion.
 * Take O(h) time (h is height of tree)
 * In the best case in which tree is perfectly balance, h is log(n).
 *      the search space is halved after each step
 * In the worst case in which tree has only left site or right site, h is n
 */
struct bst_node *_tree_search_recur(struct bst_node *root, int key) {
    if (root == NULL) return NULL;
    if (key == root->data)
        return root;

    if (key < root->data)
        return _tree_search_recur(root->left, key);
    else
        return _tree_search_recur(root->right, key);
}
struct bst_node *tree_search(struct bst_tree *t, int key) {
    return _tree_search_recur(t->root, key);
}

// insert
bool _tree_insert_recur(struct bst_node **root, int key) {
    if (*root == NULL) {
        *root = node_init(key);
        return true;
    }

    if (key == (*root)->data)
        return false;

    if (key < (*root)->data)
        return _tree_insert_recur(&(*root)->left, key);
    else
        return _tree_insert_recur(&(*root)->right, key);
}
bool tree_insert(struct bst_tree *t, int key) {
    if (t == NULL)
        return false;

    bool inserted = _tree_insert_recur(&t->root, key);
    if (inserted)
        t->size++;

    return inserted;
}

// remove
struct bst_node *tree_remove(struct bst_tree *t, int key) {
    return NULL;
}

/** depth first L-N-R traversal with recursion */
void _tree_inorder_traverse_recur(struct bst_node *node, void(*op)(struct bst_node *node)) {
    if (node == NULL)
        return;

    _tree_inorder_traverse_recur(node->left, op);
    (*op)(node);
    _tree_inorder_traverse_recur(node->right, op);
}
void tree_inorder_traverse(struct bst_tree *t, void(*op)(struct bst_node *node)) {    // LNR
    if (t == NULL && tree_is_empty(t))
        return;

    _tree_inorder_traverse_recur(t->root, op);
}

/** breath first traversal */
void tree_breadth_traverse(struct bst_tree *t, void(*op)(struct bst_node *node)) {
    if (t == NULL || tree_is_empty(t))
        return;

    struct queue *q = queue_init(tree_size(t));
    queue_add(q, t->root);

    while (!queue_is_empty(q)) {
        struct bst_node *pnode = (struct bst_node*)queue_remove(q);
        (*op)(pnode);

        if (pnode->left != NULL)
            queue_add(q, pnode->left);
        if (pnode->right != NULL)
            queue_add(q, pnode->right);
    }
}

int _tree_height_recur(struct bst_node *node) {
    if (node == NULL)
        return 0;

    int left_height = _tree_height_recur(node->left);
    int right_height = _tree_height_recur(node->right);
    return left_height > right_height ? left_height+1 : right_height+1;
}
int tree_height(struct bst_tree *t) {
    if (t == NULL)
        return -1;

    return _tree_height_recur(t->root);
}

int _tree_count_leaves_recur(struct bst_node *node) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;

    return _tree_count_leaves_recur(node->left) + _tree_count_leaves_recur(node->right);
}
int tree_count_leaves(struct bst_tree *t) {
    if (t == NULL)
        return -1;
    return _tree_count_leaves_recur(t->root);
}
