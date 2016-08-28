/*
 * tree.h
 * binary search tree
 *
 *  Created on: Mar 22, 2016
 *      Author: tunm
 */

#ifndef BST_TREE_H_
#define BST_TREE_H_

#include <stddef.h>
#include "../../common/common.h"

//------------------------------------
// binary search tree
//------------------------------------
struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst_tree {
    struct bst_node *root;
    size_t size;
};
//------------------------------------

struct bst_node *node_init(int data);
struct bst_tree *tree_init();

size_t tree_size(struct bst_tree *t);
bool tree_is_empty(struct bst_tree *t);
int tree_height(struct bst_tree *t);
int tree_count_leaves(struct bst_tree *t);
void tree_print(struct bst_tree *t);

// search, insert, remove
struct bst_node *tree_search(struct bst_tree *t, int key);
bool tree_insert(struct bst_tree *t, int key);
struct bst_node *tree_remove(struct bst_tree *t, int key);

// traverse
void tree_inorder_traverse(struct bst_tree *t, void(*op)(struct bst_node *node));   // LNR
void tree_preorder_traverse(struct bst_tree *t, void(*op)(struct bst_node *node));  // NLR
void tree_postorder_traverse(struct bst_tree *t, void(*op)(struct bst_node *node)); // LRN
void tree_breadth_traverse(struct bst_tree *t, void(*op)(struct bst_node *node));   // breadth order

#endif /* BST_TREE_H_ */
