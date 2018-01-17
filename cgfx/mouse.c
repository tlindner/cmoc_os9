#include <cgfx.h>

asm error_code
_cgfx_ss_mouse(path_id path, int sample_rate, int timeout, int autofollow)
{
    asm
    {
_sysret	EXTERNAL
		lda		2+2+1,s		get sample rate byte
		ldb		2+2+3,s		get timeout byte
		tfr		d,x
		pshs	y
		ldy		2+2+2+4,s	get autofollow flag
		lda		2+2+1,s		get path
		ldb 	#SS_Mouse
		os9		I$SetStt
		puls	y

os9err0
		lbra	_sysret
	}
}

asm error_code
_cgfx_ss_mssig(path_id path, int signo)
{
    asm
    {
		ldx		2+2,s		get signal number
		lda		2+1,s		get path
		ldb		#SS_MsSig
		os9		I$SetStt
		bra		os9err0
	}
}

asm error_code
_cgfx_gs_mouse(path_id path, MSRET *mpkt)
{
    asm
    {
		pshs 	y
		ldx 	2+2+2,s		get mouse packet pointer
		lda 	2+2+1,s		get path
		ldy 	2+2+4,s		NOT SURE WHAT THIS IS!
		ldb 	#SS_Mouse
		os9 	I$GetStt
		puls	y
		bra 	os9err0
	}
}