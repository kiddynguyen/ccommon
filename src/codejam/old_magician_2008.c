/*
 * old_magician_2008.c
 *
 *  Created on: Mar 27, 2016
 *      Author: konai
 */

#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[]) {
    char *ifname = argv[1];
    char *ofname = argv[2];
    FILE *ifp = fopen(ifname, "r");
    FILE *ofp = fopen(ofname, "w");

    int ncases, i, nwhites, nblacks;
    char **inputs = readinput(ifp, &ncases);
    char *pair[2];
    for (i = 0; i < ncases; i++) {
        printf("line[%d]: %s; ", i, inputs[i]);
        strtoks(inputs[i], " ", pair);
        printf("pair[0] = %s; pair[1] = %s; ", pair[0], pair[1]);
        nwhites = atoi(pair[0]);
        nblacks = atoi(pair[1]);
        printf("nwhites = %d; nblacks = %d\n", nwhites, nblacks);
        fprintf(ofp, "Case #%d: %s", i+1, nblacks == 0 ? "WHITE" : "BLACK");
        if (i < ncases-1)
            fprintf(ofp, "\n");
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
