/************************************
 * Alarm Functions                  *
 * Copyright (c) 1989 by Mike Sweet *
 ************************************/

asm error_code
_cgfx_alarm_set(void *time_buffer)
{
	asm
	{
        ldx 2,s
        ldd #1
        bra return
    }
}

asm error_code
_cgfx_alarm_get(void *time_buffer)
{
	asm
	{
        ldx 2,s
        ldd #2
        bra return
    }
}

asm error_code
_cgfx_alarm_clear(void)
{
	asm
	{
        clra
        clrb

return  os9 F$Alarm
        bcs error
        clra
        clrb
        rts

error   clra
        std errno,y
        ldd #-1
        rts
    }
}

asm error_code
_cgfx_alarm_signal(void *time_buffer, int signo)
{
	asm
	{
        pshs y
        os9 F$ID
        puls y
        ldx 2,s
        ldb 5,s
        bra return
    }
}