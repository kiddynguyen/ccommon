/*
 * getline.h
 *
 *  Created on: Jan 20, 2016
 *      Author: konai
 */

#ifndef FGETS_H_
#define FGETS_H_

/**
 * read next line of 'file' to s (include new line character).
 * return number of characters read.
 * assume that s is big enough
 */
char *fgets1(char *s, int maxline, FILE *file);

#endif /* FGETS_H_ */
