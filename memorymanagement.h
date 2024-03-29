#ifndef MEMORYMANAGEMENT_H
#define MEMORYMANAGEMENT_H


#include <stdint.h>
#include <comp421/hardware.h>
#include <comp421/yalnix.h>

#include "interrupthandlers.h"


#define VALID   1 
#define INVALID 0
#define FREE 1
#define UNFREE 0  

int vm_enabled;

typedef void (*ivt_entry_t)(ExceptionInfo* );

// Stores the interrupt vector table
ivt_entry_t ivt[TRAP_VECTOR_SIZE];

// Keeps track of whether the first context switch has been completed
int first_return;

// Stores the current kernel break address
uintptr_t kernelbrk;

// Manages a list of free pages
unsigned int free_head;
int num_free_pages;

// Manages a heap of free page tables
int *free_tables;
int num_free_tables;

// Stores the address of the region 1 page table
uintptr_t ptaddr1;
struct pte *pt1;

// Stores the address and index of the borrowed PTE
void *borrowed_addr;
int borrowed_index;

// Temporarily buffers borrowed PTEs if required
struct pte pte_buffer[4];
int pte_count;


// Function prototypes
int GetPage ();
void FreePage (int , int );
void BorrowPTE ();
void ReleasePTE ();
uintptr_t GetPageTable ();
int InitPageTable (uintptr_t );
void FreePageTable (uintptr_t );
void CopyKernelStack (uintptr_t );


#endif
