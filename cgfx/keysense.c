#include <cgfx.h>

/******************************
 * Keysense functions for
 * MW C.  Include file is
 * called "keysense.h"
 * by Mike Sweet 8/31/89
 */


asm int
_os_ss_keysense(path_id path, int flag)
{
    asm
    {
_os9err EXTERNAL
_sysret EXTERNAL
		ldx 4,s		get flag
		lda 3,s		get byte
		ldb #SS_KySns
		os9 I$SetStt
		lbcs _os9err
		lbra _sysret
	}
}
 
asm int
_os_gs_keysense(path_id path, int *keys)
{
    asm
    {
_os9err EXTERNAL
		lda 3,s get 'path'
		ldb #SS_KySns
		os9 I$GetStt
		lbcs _os9err
		tfr a,b
		clra
		std [4,s]
		lbra _sysret
	}
}
