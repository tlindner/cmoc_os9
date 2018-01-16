#include <io.h>

asm error_code
_os_ss_attr(char *pathname, int perm)
{
	asm
	{
_sysret EXTERNAL
* stack:
*	0,s = return address
*	2,s = pathname pointer
*	4,s = permissions
        pshs    y,u
	    leas    -16,s 
		bsr     openfile
		bcs     goexit 
		pshs    a,y 
		os9     F$ID 
		cmpy    #0 
		beq     userok
		ldb     #E$FNA
		cmpy    1,x 
		orcc    #1 
		bne     goexit 
userok  ldb     28,s        get perm on stack 
		stb     ,x 
		puls    a,y 
		ldb     #SS_FD
		os9     I$SetStt 
		bcs     goexit 
		os9     I$Close 
goexit  leas    16,s 
		puls    y,u 
		lbra    _sysret 
openfile
    	lda     #2 
		ldx     16+4+2+2,s 		get path
		os9     I$Open 
		bcc     getfd
        rts
getfd 
        leax    2,s 
		ldy     #16
		ldb     #SS_FD
		os9     I$GetStt 
		rts
	}
}
