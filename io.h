#ifndef IO_H
#define IO_H


#include <comp421/hardware.h>

#include "queues.h"


// Defines possible states for each terminal
// #define FREE 0
#define BUSY 1


// Creates a structure to represent a kernel buffer
struct buffer {
	char *data;
	int size;
};

// Creates a structure to store data for a single terminal
struct terminal {
	struct buffer *input_bufs;
	int lines;
	struct queue *read_procs, *write_procs;
	short term_state;
};


// Declares an array of structures to store terminal data
struct terminal term[NUM_TERMINALS];


#endif
