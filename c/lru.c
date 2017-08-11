#include <stdio.h>
#include <stdlib.h>

typedef struct qnode {
    struct qnode *prev, *next;
    unsigned page_number;
} qnode;

typedef struct queue {
    unsigned count;
    unsigned no_of_frames;
    qnode *front, *back;
} queue;

typedef struct hash {
    int capacity;
    qnode * *array;
} hash;

int main() {
    return 0;
}