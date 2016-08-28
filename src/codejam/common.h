/*
 * common.h
 *
 *  Created on: Mar 27, 2016
 *      Author: konai
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#define MAXLINE 1000

char **readinput(FILE *fp, int *ncases);
int strtoks(char *str, char *delim, char *words[]);

#endif /* COMMON_H_ */
