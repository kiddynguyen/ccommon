/*
 * avl_app.c
 *
 *  Created on: May 14, 2016
 *      Author: kiddy
 */
#include <stdio.h>
#include "avl_tree.h"

void print_node(struct avl_node *node) {
    printf ("%d(h=%d) ", node->data, _tree_height_recur(node));
}

int main(int argc, char *argv[]) {
    struct avl_tree *tree = tree_init();
    tree_insert(tree, 5);
    tree_insert(tree, 7);
    tree_insert(tree, 4);
    tree_insert(tree, 2);
    tree_insert(tree, 3);
//    tree_insert(tree, 2);

    tree_inorder_traverse(tree, print_node);
    printf("\ntree height: %d\n", tree_height(tree));
}
