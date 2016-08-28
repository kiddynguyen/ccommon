/*
 * string_compare.c
 *
 *  Created on: Dec 26, 2015
 *      Author: konai
 */

int strcmp1(char *str1, char *str2) {
    int i;
    for (i = 0; str1[i] == str2[i]; i++) {
        if (str1[i] == '\0')
            return 0;
    }

    return str1[i] - str2[i];
}

int strcmp2(char *str1, char *str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0')
            return 0;
        i++;
    }

    return str1[i] - str2[i];
}

int strcmp3(char *str1, char *str2) {
    while (*str1 == *str2) { // compare 2 characters at positions str1 and str2 pointing
        if (*str1 == '\0')
            return 0;

        str1++; str2++; // move to next character
    }

    return *str1 - *str2;
}

int strcmp4(char *str1, char *str2) {
    while (*str1++ == *str2++) // compare str1 and str2 first, increase str1 and str2 by 1
        if (*str1 == '\0')
            return 0;

    return *str1 - *str2;
}
