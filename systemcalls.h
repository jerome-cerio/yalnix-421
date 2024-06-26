#ifndef SYSTEMCALLS_H
#define SYSTEMCALLS_H

#include <comp421/hardware.h>

// System call handler prototypes
int KernelFork (int );
int KernelExec (char* , char** , ExceptionInfo* );
void KernelExit (int );
int KernelWait (int* );
int KernelGetPid ();
int KernelBrk (void* );
int KernelDelay (int );
int KernelTtyRead (int , void* , int );
int KernelTtyWrite (int , void* , int );

#endif
