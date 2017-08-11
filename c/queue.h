#include "hash.h"

#ifndef QUEUE_H // include quard
#define QUEUE_H

typedef struct queue {
    unsigned count;
    unsigned no_of_frames;
    qnode *front, *back;
} queue;

// creates queue
queue *new_queue(int no_of_frames);

// checks if there is an available slot in the memory
int are_all_frames_full(queue *q);

// checks if queue is empty
int is_queue_empty(queue *q);

// remove from queue
void dequeue(queue *q);

// add to queue
void enqueue(queue *q, hash *h, unsigned page_number);

#endif // QUEUE_H