#include "qnode.h"

#ifndef HASH_H // include quard
#define HASH_H

typedef struct hash {
    int capacity;
    qnode * *array;
} hash;

// create hash of given capacity
hash *new_hash(int capacity);

#endif // HASH_H
