/*
 * strstr.h
 *
 *  Created on: Jan 20, 2016
 *      Author: konai
 */

#ifndef STRSTR_H_
#define STRSTR_H_

/**
 * check if 'pattern' is in 's', return position
 * use pointer
 */
int strstr1(char *s, char *pattern);
/**
 * check if 'pattern' is in 's', return position
 * use array index
 */
int strstr2(char *s, char *pattern);

#endif /* STRSTR_H_ */
