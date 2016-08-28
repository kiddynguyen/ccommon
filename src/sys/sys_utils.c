/*
 * sysutil.c
 *
 *  Created on: Mar 25, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

/** Get current time in seconds */
long current_time() {
    return time(NULL); // time in seconds from 1/1/1970
}

void do_sleep(long seconds) {
    sleep(seconds);
}
