#include <io.h>

asm int
getstat(int stat, int param)
{
    asm
    {
_os9err	EXTERNAL
_sysret	EXTERNAL
		pshs  y,u 		    save off params
		lda   4+2+3,s 		get ?
		ldb   4+2+1,s 		get stat code
		beq   L003c 		branch if zero (SS_Opt)
		cmpb  #SS_Ready
		beq   L003e 
		cmpb  #SS_Size
		beq   L0024 
		cmpb  #SS_Pos
		beq   L0024 
		cmpb  #SS_EOF
		beq   L003e 
		cmpb  #SS_DevNm
		beq   L003c 
		cmpb  #SS_FD
		beq   L0039 
		ldb   #E$UnkSvc
		bra   L0029 
L0024 	os9 I$GetStt 
 		bcc   L002e 
L0029 	puls  y,u 
 		lbra  _os9err 
L002e 	stx   [10,s] 
		ldx   10,s 
		stu   2,x 
		clrb   
		clra   
		puls  y,u,pc 
L0039 	ldy   12,s 
L003c 	ldx   10,s 
L003e 	os9 I$GetStt 
		puls  y,u 
		lbra  _sysret
	}
} 

asm int
setstat(int stat, int param)
{
    asm
    {
        pshs  y,u 
		lda   9,s 
		ldb   7,s 
		beq   L0096         branch if zero (SS_Opt)
		cmpb  #SS_Size 
		beq   L0094 
		cmpb  #SS_Reset 
		beq   L0096 
		cmpb  #SS_WTrk 
		beq   L0091 
		cmpb  #SS_Frz 
		beq   L00a6 
		cmpb  #SS_SPT 
		beq   L0096 
		cmpb  #SS_SQD
		beq   L00a6 
		cmpb  #SS_DCmd
		beq   L009a 
		cmpb  #SS_FD
		beq   L0096 
		cmpb  #SS_Ticks
		beq   L0096 
		cmpb  #SS_Lock
		beq   L0094 
		cmpb  #SS_BlkRd
		beq   L0091 
		cmpb  #SS_BlkWr
		beq   L0091 
		cmpb  #SS_ELog
		beq   L0091 
		cmpb  #SS_SSig
		beq   L0096 
		cmpb  #SS_Relea
		beq   L00a6 
		ldb   #E$UnkSvc
		puls  y,u 
		lbra  _os9err 
L0091 	ldy   14,s 
L0094 	ldu   12,s 
L0096 	ldx   10,s 
 		bra   L00a6 
L009a 	tfr   a,b 
		lda   11,s 
		ldx   12,s 
		ldy   14,s 
		ldu   16,s 
L00a6 	os9 I$SetStt 
 		puls  y,u 
 		lbra  _sysret 
 	}
}
