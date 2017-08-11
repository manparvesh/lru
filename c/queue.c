#include <stdlib.h>
#include "queue.h"
#include "hash.h"

// creates queue
queue *new_queue(int no_of_frames) {
    queue *q = (queue *) malloc(sizeof(queue));
    q->count = 0;
    q->no_of_frames = no_of_frames;
    q->front = q->back = NULL;
    return q;
}

// checks if there is an available slot in the memory
int are_all_frames_full(queue *q) {
    return q->count == q->no_of_frames;
}

// checks if queue is empty
int is_queue_empty(queue *q) {
    return q->back == NULL;
}

// remove from queue
void dequeue(queue *q) {
    // nothing in queue
    if (is_queue_empty(q)) { return; }

    // if only node in list
    if (q->front == q->back) { q->front = NULL; }

    // change back and remove previous one
    qnode *temp = q->back;
    q->back = q->back->prev;

    if (q->back) { q->back->next = NULL; }
    free(temp);

    q->count--;
}

// add to queue and hash
void enqueue(queue *q, hash *h, unsigned page_number) {
    // if queue is full, remove last element
    if (are_all_frames_full(q)) {
        h->array[q->back->page_number] = NULL;
        dequeue(q);
    }

    // create new node with given page number, add new node to the front of queue
    qnode *temp = new_qnode(page_number);
    temp->next = q->front;

    // if queue is empty, change both front and back pointers
    if (is_queue_empty(q)) { q->back = q->front = NULL; }
    else {
        // change the front
        q->front->prev = temp;
        q->front = temp;
    }

    // add page entry to hash
    h->array[page_number] = temp;

    // increment no of pages
    q->count++;
}
