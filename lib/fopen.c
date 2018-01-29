#include <stdio.h>
#include <os.h>

asm FILE *
fdopen(int filedes, char *mode)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = file descriptor
*	4,s = mode
        pshs        u
        ldu         #0
        ldx         2+4,s           mode
        ldd         2+2,s           filedes
        bra         open3
    }
}


asm FILE *
fopen(char *pathname, char *mode)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = pathname pointer
*	4,s = mode
        pshs        u
        ldx         2+4,s           mode
        ldu         2+2,s           path
        lbsr        openit          pathname in D or -1
        ldu         #0              no file pointer yet
        std         -2,s
        bpl         open2
open1   clra
        clrb
        puls        u,pc
    }
}


asm FILE *
freopen(char *pathname, char *mode, FILE *stream)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = pathname pointer
*	4,s = mode
*	6,s = FILE stream
        pshs        u
        ldd         2+6,s           stream
        pshs        d
_fclose EXTERNAL
        lbsr        _fclose         close nor path
        leas        2,s
        ldx         2+4,s           action
        ldu         2+2,s           filename
        lbsr        openit          ret pn in d or -1
        std         -2,s
        bmi         open1           error
        ldu         2+6,s           get stream
open2   ldx         2+4,s           mode
open3   lbsr        setiob
open4   puls        u,pc

*  input:   d = pn
*           x = *mode
*           u = *_iob = fp
*  output:  _iob allocated of necessary, iniz _flag in any case
*            to _READ or _WRITE or both.  Stash path num in _fd.
*            setbase will fill in the rest since _iob is static
*            and all zeros

setiob
        pshs        d               save path number
        stu         -2,s            check for fp
        bne         setiob3         if already have one
_iob    EXTERNAL
        leau     __iob,y
        lda         #_NFILE
setiob1 ldb         6+1,u           _flag
        andb        #_READ+_WRITE
        beq         setiob3         found empty one
        leau        13,u            _iobsiz
        deca
        bne         setiob1
        ldd         #E$PthFul
        std         _errno,y
        clra
        clrb
        puls        x,pc

setiob3 puls        d               recover path number
        std         8,u             _fd
        ldd         1,x             second and third chars
        tsta                        make sure something there
        beq                         setiob5
        cmpa        #'+'            update?
        beq         setiob4         was ?+
        cmpb        #'+'
        bne         setiob5         was not ??+
setiob4 ldb         #_READ|_WRITE
        bra         setiob8

setiob5 ldb         ,x
        cmpb        #'r'            read?
        beq         setiob6
        cmpb        #'d'            dir?
        bne         setiob7
setiob6 ldb         #_READ
        bra         setiob8

setiob7 ldb         #_WRITE
setiob8 orb         6+1,u           _flag
        stb         6+1,u           _flag
        ldd         2,u             _base
        addd        11,u            _bufsiz
        std         ,u              _ptr
        std         4,u             _end
        tfr         u,d
        rts

*  input:   x = *mode
*           u = *filename
*  output:  d = path number, and file opened or created in proper mode

* first figure out auxilliary modes
openit  clra
        clrb
        pshs        d,u
        ldd         1,x             second and third chars
        tsta
        beq         openit4         only one char given
        cmpa        #'x'
        bne         openit2         if not ?x
        cmpb        #'+'            update?
        bne         openit1         if not ?x+
        ldd         #$0007          ewr cause is ?x+
        bra         openit3

openit1 ldd         #$0004          e
        bra         openit3

openit2 cmpa        #'+'            ?+
        bne         openit9
        ldd         #$0003          rw cause is ?+
openit3 std         ,s

* now figure out primary mode
openit4 ldb         ,x
        cmpb        #'r'
        bne         openit5
        ldd         ,s
        orb         #1
        bra         openit11

openit5 cmpb        #'a'
        bne         openit6
        ldd         ,s
        orb         #$02            w
        pshs        d
        tfr         u,d
open    EXTERNAL
        lbsr        open
        leas        2,s
        std         2,s             save pn
        cmpd        #-1
        beq         openit7         assume not there
        ldu         #2              from end
        ldx         #0              with 0 offset
        pshs        d
        pshs        x,u
        pshs    x
lseek   EXTERNAL
        lbsr        lseek
        leas        6,s
        puls        d               recover path number
        bra         openit13

openit6 cmpb        #'w'
        bne         openit8
openit7 ldd         ,s
        orb         #$02 w
        pshs        d
        tfr         u,d
creat   EXTERNAL
        lbsr        creat
        bra         openit12

openit8 cmpb        #'d'
        beq         openit10
openit9 ldd         #E$BMode
erret   std         _errno,y
        ldd         #-1
        bra         openit13

openit10 ldd        ,s
        orb         #$81            dir + read
* andb #$fd wipe write
openit11 pshs       d
        tfr         u,d
        lbsr        open
openit12 leas       2,s
openit13 leas       4,s
        rts
    }
}