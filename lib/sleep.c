#include <os.h>

asm error_code
_os9_sleep(int *ticks)
{
	asm
	{
_sysret EXTERNAL
* stack:
*	0,s = return address
*	2,s = address of tick count [inout]
	    ldx [2,s]
	    os9 F$Sleep
	    stx [2,s]
	    lbra _sysret
    }
}
