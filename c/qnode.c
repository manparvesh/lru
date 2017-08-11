#include <stdlib.h>
#include "qnode.h"

qnode *new_qnode(unsigned page_number) {
    qnode *temp = (qnode *)malloc(sizeof(qnode));
    temp->page_number = page_number;
    temp->prev = temp->next = NULL;
    return temp;
}
