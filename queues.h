#ifndef QUEUES_H
#define QUEUES_H


#include "processes.h"


// Declares structures to allow PCB manipulation
struct pcb;
struct pcb_node;


// Structure of a process queue
struct queue {
    struct pcb_node *head;
    struct pcb_node *tail;
    int size;
};

// Manages the ready processes
struct queue ready;


// Function prototypes
void qinit (struct queue* );
void enq (struct queue* , struct pcb* );
struct pcb* deq (struct queue* );
struct pcb* peekq (struct queue );
int qempty (struct queue );
void qdestroy (struct queue* );


#endif
