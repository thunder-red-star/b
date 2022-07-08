struct bitarray {
    unsigned char *bits;
    int size;
};

struct bitarray *bitarray_create(int size);
void set(const struct bitarray *ba, int index, int value);
int get(const struct bitarray *ba, int index);
void setAll(struct bitarray *ba, int value);
void destroy(struct bitarray *ba);
void toString(const struct bitarray *ba);