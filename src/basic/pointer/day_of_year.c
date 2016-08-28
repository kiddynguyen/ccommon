/*
 * multi_dimens_array.c
 *
 *  Created on: Jan 9, 2016
 *      Author: konai
 */
#include <stdio.h>
#include <stdlib.h>

// must specify sizes of array
static int *month_ndays[2] = {
        { 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 },
        { 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 }
};

// by default, the fist is 0, next is 1, and so on...
enum bool { FALSE, TRUE };

/** check if a year is leap */
enum bool is_leapyear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/**
 * Get day of year from month and day of month
 *  month in range of 0 - 11
 *  mday in range of 1 - 31
 */
int day_of_year(int year, int month, int mday);

/**
 * Get month and day of month from day of year
 */
void month_day(int year, int yday, int *pmonth, int *pmday);

void main(int argc, char *argv[]) {
//    if (argc < 4) {
//        printf("Missing params");
//        return;
//    }
//
//    // note: argv[0] is the name of program,
//    // arguments passed by user started from argv[1]
//    int year = atoi(argv[1]);
//    int month = atoi(argv[2]);
//    int mday = atoi(argv[3]);
//
//    int yday = day_of_year(year, month, mday);
//    printf("yday = %d\n", yday);

    if (argc < 3) { // because by convention, argv[0] is the name of program
        printf("missing params");
        return;
    }

    int year = atoi(argv[1]);
    int yday = atoi(argv[2]);
    int pmonth, pmday;

    month_day(year, yday, &pmonth, &pmday);

    printf("month: %d\n", pmonth);
    printf("pmday: %d\n", pmday);
}

int day_of_year(int year, int month, int mday) {
    int *mdays = is_leapyear(year) ? month_ndays[1] : month_ndays[0];
    int yday = mday, i;

    for (i = 0; i < month; i++)
        yday += mdays[i];

    return yday;
}

void month_day(int year, int yday, int *pmonth, int *pmday) {
    *pmday = yday, *pmonth = 0;
    int *mdays = is_leapyear(year) ? month_ndays[1] : month_ndays[0];

    while (*pmday > mdays[*pmonth]) {
        *pmday -= mdays[*pmonth];
        (*pmonth)++;
    }
}
