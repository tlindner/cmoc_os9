#include <cgfx.h>

asm error_code
_cgfx_mousexy(path_id path, int *x, int *y)
{
    asm
    {
* Get the column and row the mouse pointer is over and return it in the variables pointed to by 'column'
* and 'row'.  Returns 0 on success, -1 if pointer is outside the window, or error code.
		pshs y
		leas -32,s reserve space for the mouse info packet
		leax ,s
		lda 32+2+2+1,s get 'path'
		ldb #SS_Mouse
		ldy #0 automatically select from right or left mouse
		os9 I$GetStt
		bcs nogood return -1 if this call was unsuccessful

		lda 0,s check pt_valid -- are we the current interactive device?
		beq nogood no, return -1
		lda 22,s pt_stat on the current window?
		cmpa #WR_OFWIN off window?
		beq nogoodneg no, return -1

		ldd 28,s get the window relative xcor
		lsra divide by 8
		rorb
		lsra
		rorb
		lsra
		rorb
		std [38,s] and save it in 'column'

		ldd 30,s get the window relative ycor
		lsra divide by 8
		rorb
		lsra
		rorb
		lsra
		rorb
		std [32+2+2+4,s] and save it in 'row'

		ldb 9,s pt_cbsb
		lslb
		orb 8,s pt_cbsa return button status

return	leas 32,s restore stack pointer
		puls y,pc return to caller
 
nogoodneg
		ldd #-1
		bra	return
		
nogood	clra		clear high byte in D
		bra return
 	}
}