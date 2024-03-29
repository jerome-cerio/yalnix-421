#ifndef PROCESSES_H
#define PROCESSES_H


#include <stdint.h>

#include <comp421/hardware.h>
#include <comp421/yalnix.h>

#include "queues.h"
#include "io.h"


// States a process may be in
enum state_t {RUNNING, READY, DELAYED, READING, WRITING, WAITING, TERMINATED};


// Structure of a PCB
struct pcb {
    unsigned int pid;
    enum state_t state;
    uintptr_t ptaddr0;
    int used_npg;
    uintptr_t user_stack_base;
    uintptr_t brk;
    SavedContext ctx;
    int clock_ticks;
    struct buffer input_buf;
    struct buffer output_buf;
    struct pcb *parent;
    struct proc_list *running_chd;
    struct queue *exited_chd;
    int exit_status;
};

// Structure of a PCB frame
struct pcb_node {
    struct pcb *proc;
    struct pcb_node *next;
};

// Declares structures to allow PCB manipulation
struct pcb;
struct pcb_node;


// Structure of a process list
struct proc_list {
    struct pcb_node *head;
    int size;
};

// Manages the blocked processes
struct proc_list blocked;


// Stores details of the 'idle' and 'init' processes
struct pcb idle_pcb;
struct pcb *init_pcb;

// Keeps track of the last assigned PID
unsigned int lastpid;

// Manages the active process
struct pcb *active;

// Keeps track of the time quantum for the current process
unsigned int quantum;


// Function prototypes for processes.
int InitProcess (struct pcb* , enum state_t , uintptr_t );
struct pcb* MoveProcesses (enum state_t , void* );
void RemoveProcess (struct pcb* );
SavedContext* InitContext (SavedContext* , void* , void* );
SavedContext* Switch (SavedContext* , void* , void* );
int LoadProgram (char* , char** , ExceptionInfo* );

// Function prototypes for process lists.
void linit (struct proc_list* );
void insertl (struct proc_list* , struct pcb* );
void deletel (struct proc_list* , struct pcb* );
void clockl (struct proc_list* );
void exitl (struct proc_list* );
struct pcb* readyl (struct proc_list* );
int lempty (struct proc_list );
void ldestroy (struct proc_list* );


#endif
