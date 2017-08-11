#ifndef QNODE_H // include quard
#define QNODE_H

typedef struct qnode {
    struct qnode *prev, *next;
    unsigned page_number;
} qnode;

// creates qnode
qnode *new_qnode(unsigned page_number);

#endif // QNODE_H