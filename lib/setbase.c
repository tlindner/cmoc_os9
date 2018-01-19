#include <stdio.h>
#include <io.h>

asm int
setbase(FILE *stream)
{
    asm
    {
ibrk	    EXTERNAL
_getstat	EXTERNAL

* Sets up FILE structure
            pshs  u 
            ldu   2+2,s             get FILE pointer
            ldb   7,u               get low 8 bits of _flag in FILE
            bitb  #_DEVMASK         test devmask
            bne   L0029             branch if result not zero
            leas  -32,s             else reserve space on stack
            leax  ,s                and point X to space
            ldd   8,u               get _fd from FILE
            pshs  d,x               save _fd and pointer to 32 bytes
            clra                    stdin
            clrb   
            pshs  d                 save on stack
            lbsr  _getstat          call getstat
            ldb   #$40 
            lda   6,s 
            beq   L0022 
            ldb   #$80 
L0022       leas  38,s 
            orb   7,u 
            stb   7,u 
L0029       lda   6,u 
            ora   #$80 
            sta   6,u 
            andb  #$0c 
            bne   L006c 
            ldd   11,u 
            bne   L003c 
            ldd   #$0100 
            std   11,u 
L003c       ldd   2,u 
            bne   L0051 
            ldd   11,u 
            pshs  d 
            lbsr  ibrk 
            leas  2,s 
            std   2,u 
            cmpd  #-1 
            beq   L0055 
L0051       ldb   #8 
            bra   L0060 
L0055       leax  10,u 
            stx   2,u 
            ldd   #1 
            std   11,u 
            ldb   #4 
L0060       orb   7,u 
            stb   7,u 
            ldd   2,u 
            addd  11,u 
            std   4,u 
            std   ,u 
L006c       puls  u,pc 
    }
}
