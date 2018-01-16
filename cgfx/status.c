#include <cgfx.h>

asm error_code
_cgfx_gs_crsr(path_id path, int *x, int *y)
{
    asm
    {
_Flush	EXTERNAL
		pshs	y
		lbsr	_Flush
		lda		2+2+1,s		get path
		ldb		#SS_Cursr
		bra		g0
	}
}
 
asm error_code
_cgfx_gs_scsz(path_id path, int *x, int *y)
{
    asm
    {
_sysret	EXTERNAL
_os9err	EXTERNAL
		pshs	y
		lbsr 	_Flush
		lda 	2+2+1,s
		ldb 	#SS_ScSiz
g0
		os9 	I$GetStt
		stx 	[2+2+2,s]
		sty 	[2+2+4,s]
		puls 	y
		lbra	_sysret
	}
}

asm error_code
_cgfx_gs_palt(path_id path, char *palbuf)
{
    asm
    {
		pshs 	y
		lbsr 	_Flush
		ldx 	2+2+2,s		get palette buffer pointer
		lda 	2+2+1,s		get path
		ldb 	#SS_Palet
		os9 	I$GetStt
		puls 	y,pc
	}
}

asm error_code
_cgfx_ss_mgpb(path_id path, int grpnum, int bufnum, int mapflag, int *size, char *bufaddr)
{
    asm
    {
		pshs 	y
		lbsr 	_Flush
		lda 	2+2+3,s		get group number
		ldb 	2+2+5,s		get buffer number
		tfr 	d,x
		ldy 	2+2+6,s		get mapflag
		lda		2+2+1,s		get path
		ldb 	#SS_MpGPB
		os9 	I$SetStt
		puls 	y
		lbcs	_os9err
		sty 	[2+2+8,s]	save in size pointer
	 	stx		[2+12,s]	save in bufaddr pointer
		lbra	_sysret
	}
}

asm error_code
_cgfx_gs_styp(path_id path, int *type)
{
    asm
    {
		lbsr 	_Flush
		lda 	2+1,s		get path
		ldb 	#SS_ScTyp
		os9 	I$GetStt
		lbcs 	_os9err
		tfr		a,b
		clra
		std		[4,s]
	 	lbra	_sysret
 	}
}

asm error_code
_cgfx_gs_fbrg(path_id path, int *fore, int *back, int *bord)
{
    asm
    {
		lbsr	_Flush
		lda		2+1,s		get path
		ldb		#SS_FBRgs
		os9 	I$GetStt
		lbcs	_os9err
		stx		[2+6,s]		save back
		ldx		2+2,s
		sta		1,x
		clr		,x
		clra
		std		[2+4,s]
		clrb
		rts
	}
}

asm error_code
_cgfx_ss_gip(path_id path, int msres, int msport, int kbdstrt, int kbdrpt)
{
    asm
    {
		pshs 	y
		lda 	2+2+3,s		get msres
		ldb		2+2+5,s		get msport
		tfr		d,x
		lda		2+2+7,s		get kbdstrt
		ldb		2+2+9,s		get kbdrpt
		tfr 	d,y
		lda 	2+2+1,s		get path
		ldb 	#SS_GIP
		os9 	I$SetStt
		puls 	y
		lbra	_sysret
	}
}

asm error_code
_cgfx_ss_dfpl(path_id path, char *palbuf)
{
    asm
    {
		ldx		2+2,s		get palette buffer pointer
		lda		2+1,s		get path
		ldb		#SS_DfPal
		os9 	I$SetStt
os9err1
		lbra	_sysret
	}
}

asm error_code
_cgfx_ss_mtyp(path_id path, int montype)
{
    asm
    {
		ldx		2+2,s		get monitor type
		lda		2+1,s		get path
		ldb		#SS_Montr
		os9 	I$SetStt
		bra 	os9err1
	}
}