/*
 * timeutils.h
 *
 *  Created on: Aug 28, 2016
 *      Author: kiddy
 */

#ifndef TIMEUTILS_H_
#define TIMEUTILS_H_

#include <time.h>

time_t current_time_in_secs();
long current_time_in_milisecs();
void sleep(long milisecs);

time_t calculate_duration_in_seconds();
char *format_time(time_t *time);

#endif /* TIMEUTILS_H_ */
