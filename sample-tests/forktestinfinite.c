#include <comp421/yalnix.h>
#include <comp421/hardware.h>

int
main(int argc, char **argv)
{
    while (Fork() == 0) {
	    TracePrintf(0, "CHILD\n");
    }
}
