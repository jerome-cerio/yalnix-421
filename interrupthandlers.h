#ifndef INTERRUPTHANDLERS_H
#define INTERRUPTHANDLERS_H

#include <comp421/hardware.h>

void KernelHandler (ExceptionInfo* );
void ClockHandler (ExceptionInfo* );
void IllegalHandler (ExceptionInfo* );
void MemoryHandler (ExceptionInfo* );
void MathHandler (ExceptionInfo* );
void TtyReceiveHandler (ExceptionInfo* );
void TtyTransmitHandler (ExceptionInfo* );

#endif