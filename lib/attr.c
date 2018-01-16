#include <os.h>

asm int
_os_ss_attr(int path, int permissions)
{
	asm
	{
_sysret EXTERNAL
		pshs  y,u 
		leas  -16,s 
		bsr   openfile
		bcs   goexit 
		pshs  a,y 
		os9 F$ID 
		cmpy  #0 
		beq   userok
		ldb   #$d6 
		cmpy  1,x 
		orcc  #1 
		bne   goexit 
userok		ldb   28,s 
		stb   ,x 
		puls  a,y 
		ldb   #SS_FD
		os9 I$SetStt 
		bcs   goexit 
		os9 I$Close 
goexit		leas  16,s 
		puls  y,u 
		lbra  _sysret 
openfile	lda   #2 
		ldx   24,s 		get path
		os9 I$Open 
		bcc   getfd
                rts
getfd  		leax  2,s 
		ldy   #$0010 
		ldb   #SS_FD
		os9 I$GetStt 
		rts
	}
}
