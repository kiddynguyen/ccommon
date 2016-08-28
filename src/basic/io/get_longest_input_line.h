/*
 * print_longest_input_line.h
 *
 *  Created on: Dec 18, 2015
 *      Author: konai
 */

#ifndef GET_LONGEST_INPUT_LINE_H_
#define GET_LONGEST_INPUT_LINE_H_

#define MAXLINE 1000        // max line allowed to read at one time

void get_longest_input_line();
int readline(char line[]);
void copystring(char dest[], char src[]);

#endif /* GET_LONGEST_INPUT_LINE_H_ */
