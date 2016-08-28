/*
 * system_call_io.c
 *
 *  Created on: Jun 25, 2016
 *      Author: kiddy
 */

#include <stdio.h>
#include <stdlib.h>

#include "../../common/common.h"

int main(int argc, char *argv[]) {
    int fd = 1;
    byte *buffer = (byte*) malloc(1024*sizeof(byte));
    int nread = read(fd, buffer, 1024);
}
