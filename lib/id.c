#include <os.h>

asm error_code
_os_getpid(int *pid)
{
    asm
    {
_os9err EXTERNAL
_sysret EXTERNAL

X004b equ $004b 

        pshs  y 
        os9 F$ID 
        puls  y 
        lbcs _os9err
        tfr   a,b 
        clra
        std   [2+2,s]
        lbra    _sysret
    }
}

asm error_code
_os_getuid(int *uid)
{
    asm
    {
        pshs  y 
        os9 F$ID 
        tfr   y,d
        puls  y
        lbcs   _os9err
        std    [2+2,s]
        lbra   _sysret
    }
}

asm error_code
_os_asetuid(int uid)
{
    asm
    {
        pshs  y 
        bra   L0027 
    }
}

asm error_code
_os_setuid(int uid)
{
    asm
    {
        pshs  y 
        os9 F$ID 
        tfr   y,d
        std   -2,s 
        beq   L0027 
        ldb   #$d6 
L0022   puls  y 
        lbra  _os9err 
L0027   ldy   2+2,s 
        os9     F$SUser 
        bcc   L003b 
        cmpb  #$d0 
        bne   L0022 
        tfr   y,d 
        ldy   X004b 
        std   9,y 
L003b   puls    y
        lbra    _sysret
    }
}
