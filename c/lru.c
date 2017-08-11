#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void reference_page(queue *q, hash *h, unsigned page_number) {
    qnode *req_page = h->array[page_number];

    // if page not in cache, add it
    if (req_page == NULL) { enqueue(q, h, page_number); }
    else if (req_page != q->front) {
        // unlink requested page from current location
        req_page->prev->next = req_page->next;
        if (req_page->next) { req_page->next->prev = req_page->prev; }

        // if the requested page is at the back, change back
        if (req_page == q->back) {
            q->back = req_page->prev;
            q->back->next = NULL;
        }

        // put the requested page before current front / head
        req_page->next = q->front;
        req_page->prev = NULL;

        // change prev of current front
        req_page->next->prev = req_page;

        // set front to this
        q->front = req_page;
    }
}

int main() {
    // create cache with size 4
    queue *q = new_queue(4);

    // allow 10 different pages to be requested
    hash *h = new_hash(10);

    // refer pages 1, 2, 3, 1, 4, 5
    reference_page(q, h, 1);
    reference_page(q, h, 2);
    reference_page(q, h, 3);
    reference_page(q, h, 1);
    reference_page(q, h, 4);
    reference_page(q, h, 5);

    // printing cache frames
    printf("%d ", q->front->page_number);
    printf("%d ", q->front->next->page_number);
    printf("%d ", q->front->next->next->page_number);
    printf("%d ", q->front->next->next->next->page_number);

    return 0;
}