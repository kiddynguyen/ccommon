/*
 * binary_file_io.c
 *
 *  Created on: Oct 16, 2015
 *      Author: tunm2
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 255
typedef char BYTE;

// size_t fread (void *buffer, size_t size_of_element, size_t elements_count, FILE *fpt)
// size_t fwrite (void *buffer, size_t size_of_element, size_t elements_count, FILE *fpt)
void filecopy_binary(char *from_file, char *to_file) {
    FILE *ifp = fopen(from_file, "rb");
    FILE *ofp = fopen(to_file, "wb");

    if (ifp == NULL) {
        perror("File not found");
        return;
    }

    BYTE *buffer = (BYTE*) calloc(BUFFER_SIZE, sizeof(BYTE));

    while (fread(buffer, sizeof(buffer), 1, ifp) > 0) {
        fwrite(buffer, sizeof(buffer), 1, ofp);
    }

//    Why this code failed ????
//    while (fread(buffer, sizeof(BYTE), BUFFER_SIZE, ifp) > 0) {
//        fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, ofp);
//    }

    free(buffer);

    fclose(ifp);
    fclose(ofp);
}

void serialize_struct_to_file(void *str, char *to_file) {
    FILE *fp = fopen(to_file, "wb");
    fwrite(str, sizeof(str), 1, fp);

    fclose(fp);
}

void deserialize_struct_from_file(void *str, char *from_file) {
    FILE *fp = fopen(from_file, "rb");
    fread(str, sizeof(str), 1, fp);

    fclose(fp);
}
