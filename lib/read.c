/*
 * File i/o system calls
 *
 */

#include <unistd.h>
#include <os.h>

asm int
read(int fd, char *buf, int count)
{
	asm
	{
* stack:
*	0,s = return address
*	2,s = fd
*	4,s = buffer pointer
*	6,s = read count
        pshs    y
        ldx     2+4,s           get count in Y
        lda     2+2+1,s         get fd in A
        ldy     2+6,s           get read coun tin Y
        pshs    y               save the count for later
        os9     I$Read

read1   bcc     rdexit          no problem if carry clear
        cmpb    #E$EOF          is the error EOF?
        bne     read10          bra if not
        clra                    return zero bytes on EOF
        clrb
        puls    x,y,pc

read10  puls    x,y             reset stack and data pointer
_os9err EXTERNAL
        lbra    _os9err         report error

rdexit  tfr     y,d             return read/write count in d
        puls    x,y,pc          reset stack & data pointer and return
    }
}

asm int
readln(int fd, char *buf, int count)
{
	asm
	{
* stack:
*	0,s = return address
*	2,s = fd
*	4,s = buffer pointer
*	6,s = read count
        pshs    y               save data pointer
        ldx     2+4,s           get count in Y
        lda     2+2+1,s         get fd in A
        ldy     2+6,s           get read coun tin Y
        pshs    y               save request for later
        os9     I$ReadLn        call os9
        bra     read1
    }
}
