#include <stdlib.h>
#include <string.h>

asm int
memcmp(void *s1, void *s2, size_t n)
{
	asm
	{
        pshs  y,u           save off
        ldx   4+2,s         get first parameter
        cmpx  4+4,s         compare with second parameter
        beq   same          pointers are same... equal
        ldu   4+4,s         get second parameter
        ldy   4+6,s         get third parameter (count)
        beq   same 
compare ldb   ,u+           get byte in second ptr
        subb  ,x+           subtract from first
        beq   equal         branch if equal to zero (meaning bytes at U and X are equal)
        negb   
        sex    
        bra   ret 
equal   leay  -1,y          decrement count
        bne   compare       branch if more
same    clra   
        clrb   
ret     puls  y,u,pc 
    }
}