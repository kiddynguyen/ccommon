/*
 * red_back_tree.h
 *
 *  Created on: Apr 3, 2016
 *      Author: kiddy
 */

#ifndef RB_TREE_H_
#define RB_TREE_H_

const bool RED      = false;
const bool BLACK    = true;

struct rb_node {
    void *key;
    void *value;
    struct rb_node left;
    struct rb_node right;
    struct rb_node parent;
    bool color = RED;
};

struct rb_tree {
    struct rb_node root;
};

struct rb_node *rb_node_init(void *key, void *value, bool color);
struct rb_node *rb_node_grandpt(struct rb_node *node);
struct rb_node *rb_node_uncle(struct rb_node *node);
bool rb_node_is_nil(struct rb_node *node);

struct rb_tree *rb_tree_init();
void rb_tree_inorder_print(struct rb_tree *t);

struct rb_node *rb_tree_search(struct rb_tree *t, void *key);
bool rb_tree_insert(struct rb_tree *t, void *key, void *value);
struct rb_node *rb_tree_remove(struct rb_tree *t, void *key);

#endif /* RB_TREE_H_ */
