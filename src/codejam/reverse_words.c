/*
 * Google Code Jam Africa 2010, Qualification Round
 * https://code.google.com/codejam/contest/351101/dashboard#s=p1
 *
 *  Created on: Mar 12, 2016
 *      Author: tunguyen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE BUFSIZ
#define MAXLINES 1000

void swap1(char *words[], int i, int j);
int readinput(char *lines[], int maxlines, FILE *fp);
int strtoks(char *str, char *delim, char *words[]);
void print_words(char *words[], int nwords, FILE *opfile);
void reverse_words(char *words[], int count);

int main(int argc, char *argv[]) {
    char *ifile = argv[1];
    char *ofile = argv[2];

    FILE *ipfile = fopen(ifile, "r");
    FILE *opfile = fopen(ofile, "w");

    char *lines[MAXLINES]; // pointer array
    int nlines = readinput(lines, MAXLINES, ipfile);
    int ncases = atoi(lines[0]);

    int i;
    for (i = 1; i <= ncases; i++) {
        char *words[1000];
        int nwords = strtoks(lines[i], " ", words);
        reverse_words(words, nwords);
        print_words(words, nwords, opfile);
        if (i < ncases)
            fputs("\n", opfile);
    }

    fclose(ipfile);
    fclose(opfile);
}

int readinput(char *lines[], int maxlines, FILE *fp) {
    char buf[MAXLINE];
    int count, nlines = 0;

    while ((count = readline(buf, MAXLINE, fp)) > -1 && maxlines-- > 0) {
        *lines = (char*) malloc(count*sizeof(char));
        strcpy(*lines++, buf);
        nlines++;
    }

    return nlines;
}

int readline(char *line, int maxline, FILE *fp) {
    int ch, count = 0;

    while ((ch = fgetc(fp)) != EOF && ch != '\n' && maxline-- > 0) {
        *line++ = ch;
        count++;
    }

    if (ch == EOF) // EOF is always on a new separate line
        return -1;

    *line = '\0';

    return count;
}

int strtoks(char *str, char *delim, char *words[]) {
    int i = 0;
    words[0] = strtok(str, delim);
    if (words[0] != NULL)
        while ((words[++i] = strtok(NULL, delim)) != NULL);

    return i;
}

void reverse_words(char *words[], int count) {
    int i;
    for (i = 0; i < count/2; i++)
        swap1(words, i, count-i-1);
}

void swap1(char *words[], int i, int j) {
    char *tmp = words[i];
    words[i] = words[j];
    words[j] = tmp;
}

void print_words(char *words[], int nwords, FILE *opfile) {
    int i = 0;
    while(i++ < nwords) {
        fputs(*words++, opfile);
        if (i < nwords)
            fputs(" ", opfile);
    }
}
