/*
 * mergesort.c
 *
 *  Created on: Feb 9, 2016
 *      Author: root
 */

#include <stdio.h>
#include "algorithm/sort/mergesort.h"
#include "common/common.h"

/**
 * Merge sort of linked list
 */
//struct list *mergesort2(struct list *list) {
//    if (list_size(list) == 1)
//        return list;
//
//    // divide original list to two sublists
//    int size = list_size(list);
//    int mid = size / 2;
//    struct list *list1 = list_sublist(list, 0, mid);
//    struct list *list2 = list_sublist(list, mid, size);
//
//    // recursively mergesort each sublist
//    list1 = mergesort2(list1);
//    list2 = mergesort2(list2);
//
//    // merge two sorted sublists
//    return merge2(list1, list2);
//}

/** merge two sorted lists */
//struct list *merge2(struct list *list1, struct list *list2) {
//    struct list *list = list_init();
//
//    // if last element of list1 is less than first element of list2
//    // the just append list2 to list1
//    if (list_get_last(list1)->data < list_get_first(list2)->data) {
//        list_append(list, list1);
//        list_append(list, list2);
//        return list;
//    }
//
//    // if last element of list2 is less than first element of list2
//    // the just append list1 to list2
//    if (list_get_last(list2)->data < list_get_first(list1)->data) {
//        list_append(list, list2);
//        list_append(list, list1);
//        return list;
//    }
//
//    int size1 = list_size(list1), size2 = list_size(list2);
//    int i1 = 0, i2 = 0;
//
//    while (i1 < size1 && i2 < size2) {
//        struct element *el1 = list_get_at(i1, list1), *el2 = list_get_at(i2, list2);
//        if (el1->data <= el2->data) {
//            list_insert_last(el1->data, list);
//            i1++;
//        } else {
//            list_insert_last(el2->data, list);
//            i2++;
//        }
//
//        // walked through all elements of list1
//        // just append all rest elements of list2 to list
//        if (i1 == size1) {
//            list_append(list, list_sublist(list2, i2, size2));
//            break;
//        }
//
//        // walked through all elements of list2
//        // just append all rest elements of list1 to list
//        if (i2 == size2) {
//            list_append(list, list_sublist(list1, i1, size1));
//            break;
//        }
//    }
//
//    return list;
//}

/**
 * Merge sort of array
 */
void mergesort(int list[], int left, int right) {
    if (left == right)
        return;

    int mid = (left + right) / 2;
    mergesort(list, left, mid);
    mergesort(list, mid+1, right);
    merge(list, left, mid, right);
}

void merge(int list[], int left, int mid, int right) {
    int lsize = mid-left+1, rsize = right-mid;
    int llist[lsize], rlist[rsize];
    int i, j, k;

    // copy items to two separately temp sublists
    for (i = 0; i < lsize; i++)
        llist[i] = list[left+i];
    for (j = 0; j < rsize; j++)
        rlist[j] = list[mid+1+j];

    // loop over two sublists and compare for merging
    i = 0, j = 0, k = left;
    while (i < lsize && j < rsize) {
        if (llist[i] <= rlist[j])
            list[k++] = llist[i++];
        else
            list[k++] = rlist[j++];
    }

    // append the rest of the greater sublist to result
    while (i < lsize)
        list[k++] = llist[i++];
    while (j < rsize)
        list[k++] = rlist[j++];
}
