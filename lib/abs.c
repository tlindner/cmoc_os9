#include <io.h>

asm int
abs(int v)
{
	asm
	{
        ldd   2,s 
        bpl   absex 
        nega   
        negb   
        sbca  #0 
absex   rts    
    }
}
