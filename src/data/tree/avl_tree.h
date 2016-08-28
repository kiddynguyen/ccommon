/*
 * avl_tree.h
 *
 *  Created on: Apr 3, 2016
 *      Author: kiddy
 */

#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include "../../common/common.h"

struct avl_node {
    int data;
    struct avl_node *left;
    struct avl_node *right;
    int balancer;     // left_height - right_height (-2, -1, 0, 1, 2)
};

struct avl_tree {
    struct avl_node *root;
    int size;
};

struct avl_node *node_init(int data);
struct avl_tree *tree_init();
int _tree_height_recur(struct avl_node *node);
int tree_height(struct avl_tree *t);

bool tree_insert(struct avl_tree *t, int data);
void tree_inorder_traverse(struct avl_tree *t, void(*op)(struct avl_node *bst_node));

#endif /* AVL_TREE_H_ */
