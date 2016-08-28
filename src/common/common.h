/*
 * common.h
 *
 *  Created on: Feb 27, 2016
 *      Author: konai
 */

#ifndef COMMON_H_
#define COMMON_H_

typedef char byte;
typedef enum { false, true } bool;

void uppercase(char *s);
void lowercase(char *s);

void swap1(int a[], int i, int j);
void printarr(int a[], int size);

#endif /* COMMON_H_ */
