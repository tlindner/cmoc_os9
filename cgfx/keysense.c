#include <cgfx.h>

asm int
_os_ss_keysense(path_id path, int keys)
{
    asm
    {
_os9err EXTERNAL
_sysret EXTERNAL
		ldx 	2+2,s		get flags
		lda 	2+1,s		get byte
		ldb 	#SS_KySns
		os9 	I$SetStt
		lbra 	_sysret
	}
}
 
asm int
_os_gs_keysense(path_id path, int *keys)
{
    asm
    {
_os9err EXTERNAL
		lda 	2+1,s 		get the path
		ldb 	#SS_KySns
		os9 	I$GetStt
		lbcs 	_os9err
		tfr 	a,b
		clra
		std 	[4,s]		save the flags
		lbra 	_sysret
	}
}
