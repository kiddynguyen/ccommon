/*
 * time.c
 *
 *  Created on: Aug 28, 2016
 *      Author: kiddy
 */

#include <stdio.h>
#include <stdlib.h>
#include "basic/time/timeutils.h"
#include <sys/time.h>

// time_t ~ long int
time_t current_time_in_secs() {
    time_t current = time(NULL);
    return current;
}

long current_time_in_milisecs() {
    struct timeval tval;
    gettimeofday(&tval, NULL);
    time_t tsec = tval.tv_sec;          // seconds
    suseconds_t tusec = tval.tv_usec;   // microseconds
    return tsec*1000 + tusec/1000;
}

time_t calculate_duration_in_seconds() {
    time_t start = time(NULL);
    // processing
    time_t end = time(NULL);
    return end - start;
}

char *format_time(time_t *time) {
    return ctime(time);
}

void sleep(long milisecs) {
    // TODO
}
