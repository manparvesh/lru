#include <stdlib.h>
#include "hash.h"

hash *new_hash(int capacity) {
    hash *h = (hash *) malloc(sizeof(hash));
    h->capacity = capacity;
    h->array = (qnode**) malloc(h->capacity * sizeof(qnode *));

    // init all arrays as empty
    int i;
    for (i = 0; i < h->capacity; i++) { h->array[i] = NULL; }

    return h;
}
