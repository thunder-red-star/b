#include "bitarray.h"
#include <stdio.h>
#include <stdlib.h>

extern struct bitarray *bitarray_create(int size) {
    struct bitarray *ba = malloc(sizeof(struct bitarray));
    ba->bits = calloc(sizeof(unsigned char), (size / 8 + 1));
    ba->size = size;
    return ba;
}

extern void set(const struct bitarray *ba, int index, int value) {
    if (value) {
        ba->bits[index / 8] |= (1 << (index % 8));
    } else {
        ba->bits[index / 8] &= ~(1 << (index % 8));
    }
}

extern int get(const struct bitarray *ba, int index) {
    return (ba->bits[index / 8] & (1 << (index % 8))) != 0;
}

extern void setAll(struct bitarray *ba, int value) {
    int i;
    for (i = 0; i < ba->size; i++) {
        set(ba, i, value);
    }
}

extern void destroy(struct bitarray *ba) {
    free(ba->bits);
    free(ba);
}

extern void toString(const struct bitarray *ba) {
    int i;
    for (i = 0; i < ba->size; i++) {
        printf("%d", get(ba, i));
    }
    printf("\n");
}
