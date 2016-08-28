/*
 * demo_tree.c
 *
 *  Created on: Mar 27, 2016
 *      Author: konai
 */

#include <stdio.h>
#include "bst_tree.h"

void print_node(struct bst_node *node) {
    printf("%d ", node->data);
}

int main(int argc, char *argv[]) {
    struct bst_tree *t = tree_init();
    tree_insert(t, 6);
    tree_insert(t, 4);
    tree_insert(t, 2);
    tree_insert(t, 5);
    tree_insert(t, 10);
    tree_insert(t, 12);
    tree_insert(t, 8);
    tree_insert(t, 7);
    tree_insert(t, 9);

//    int height = tree_height(t);
//    printf("height = %d\n", height);
//    int leaves = tree_count_leaves(t);
//    printf("number of leaves = %d\n", leaves);

    tree_inorder_traverse(t, print_node);
    printf("\n");

    tree_breadth_traverse(t, print_node);
    printf("\n");

    return 0;
}
