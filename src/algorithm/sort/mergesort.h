/*
 * mergesort.h
 *
 *  Created on: Aug 27, 2016
 *      Author: kiddy
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "data/list.h"

// merge sort of linked list
//struct list *mergesort2(struct list *list);
// merge sort of array
void mergesort(int list[], int left, int right);

//struct list *merge2(struct list *list1, struct list *list2);
void merge(int list[], int left, int mid, int right);

#endif /* MERGESORT_H_ */
