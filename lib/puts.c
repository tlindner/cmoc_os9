#include <stdio.h>
#include <os.h>

__norts__ asm int
puts(int c)
{
    asm
    {
* 0,s  = return address
* 2,s  = character
__iob	EXTERNAL
_putc   EXTERNAL

        pshs  u
        leax  __iob+13,y
        ldd   4,s
        pshs  d,x
        bsr   fputs
        ldb   #$0d
        stb   1,s
        lbsr  _putc
        leas  4,s
        puls  u,pc
    }
}

__norts__ asm int
fputs(int c, FILE *stream)
{
    asm
    {
* 0,s  = return address
* 2,s  = character
* 4,s  = FILE *
_putc   EXTERNAL

        pshs  u
        ldu   4,s
        ldx   6,s
        pshs  d,x
        bra   L0026
L0021   stb   1,s
        lbsr  _putc
L0026   ldb   ,u+
        bne   L0021
        leas  4,s
        puls  u,pc
    }
}
