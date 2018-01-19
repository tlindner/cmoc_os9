#include <stdio.h>

asm int
putc(int c, FILE *stream)
{
    asm
    {
__iob	EXTERNAL
__os_seek	EXTERNAL
__os_writeln	EXTERNAL
__os_close	EXTERNAL
_setbase	EXTERNAL
ftell	EXTERNAL
lseek	EXTERNAL
__os_write	EXTERNAL
_ftell	EXTERNAL

		pshs  u 
		ldu   2+2+2,s 		get FILE ptr
		ldd   6,u 			get _flag offset in FILE
		anda  #$80          mask out all but _INIT flag
		andb  #_ERR|_WRITE  mask out all but _ERR and _WRITE flags
		cmpb  #_WRITE       error clear and JUST write?
		bne   badexit       nope, exit with error
		cmpa  #$80          initialized?
		beq   inited        branch if so
		pshs  u             put FILE pointer on stack
		lbsr  _setbase      setup FILE pointer
		leas  2,s           clean up stack 
inited 	ldd   6,u           get _end pointer in FILE
		andb  #4 
		beq   L004b 
		ldd   #1			write 1 character
		pshs  d 			push count on stack
        leax  ,s			point X to count
        pshs  x				push pointer
		leax  9,s			point to character
		ldd   8,u			get _fd path in FILE			 
		pshs  d,x 			push path and pointer to char
		ldb   7,u           get _flag word in FILE 
		andb  #_SCF         SCF?
		beq   L0035         branch if not
		lbsr  __os_writeln
		bra   L0038 
L0035 	lbsr  __os_write 
L0038 	leas  8,s 			clean up stack
		cmpd  #0 			success?
		beq   L0079 		branch if so
		ldb   7,u           get _flag word in FILE
		orb   #_ERR         mark error
		stb   7,u           save
badexit	ldd   #-1           return -1 as result
 		puls  u,pc          bye!
L004b 	anda  #1 
		bne   L0058 
		pshs  u 
		lbsr  L00fd 
		std   ,s++ 
		bne   badexit 
L0058 	ldx   ,u 
		ldb   5,s 
		stb   ,x+ 
		stx   ,u 
		cmpx  4,u 
		bcc   L0070 
		ldb   7,u 
		andb  #$40 
		beq   L0079 
		ldb   5,s 
		cmpb  #$0d 
		bne   L0079 
L0070 	pshs  u 
		lbsr  L00fd 
		std   ,s++ 
		bne   badexit 
L0079 	ldd   4,s               clean up stack
 		puls  u,pc              bye!
 	}
 }
 
asm int
putw(int w, FILE *stream)
{
    asm
    {
		pshs  u
		ldu   2+2+2,s           get FILE pointer
		ldb   2+2,s             get upper 8 bits of word
		pshs  d,u               make room on stack
		lbsr  putc              put it
		ldb   4+2+2+1,s         get lower 8 bits of word
		stb   1,s               save in stack location
		lbsr  putc              put it
		leas  4,s               clean up stack
		puls  u,pc 

_tidyup: 
        pshs  u 
 		leax  __iob,y           point to base IOB
		ldb   #_NFILE           get number of FILE ptrs
		pshs  b                 save counter
L009d 	pshs  x 
		lbsr  fclose            close FILE
		puls  x 
		leax  13,x              point to next FILE
		dec   ,s 
		bne   L009d 
		puls  b,u,pc 
	}
}

asm int
fclose(FILE *stream)
{
    asm
    {
		pshs  u 
		ldu   2+2,s             get FILE ptr
		lbeq  badexit 
		ldd   6,u               get _flag word
		lbeq  badexit           branch if zero
		andb  #_WRITE           write mode?
		beq   L00c5             no
		pshs  u                 push FILE ptr
		bsr   fflush            flush
		leas  2,s               clean up stack
		bra   L00c7 
L00c5 	clra   
 		clrb   
L00c7 	pshs  d 
		ldd   8,u               get path
		pshs  d 
		lbsr  __os_close        close
		leas  2,s               clean up stack
		clra   
		clrb   
		std   6,u               clear _flag word
		puls  d,u,pc            clear stack and return
	}
}


asm int
fflush(FILE *stream)
{
    asm
    {
		pshs  u 
		ldu   2+2,s             get FILE ptr
		lbeq  badexit           exit if null
		ldd   6,u               get _flags word 
		andb  #_ERR|_WRITE
		cmpb  #_WRITE
		lbne  badexit 
		anda  #$80              initialized?
		bne   finited           branch if so
		pshs  u 
		lbsr  _setbase          initialize
		leas  2,s               clean up stack
finited
     	pshs  u                 
		bsr   L00fd 
		leas  2,s 
		puls  u,pc 
L00fd 	pshs  u                 save FILE ptr
		ldu   4,s 
		leas  -4,s 
		lda   6,u 
		anda  #1 
		bne   L012c 
		ldd   ,u 
		cmpd  4,u 
		beq   L012c 
		clra   
		clrb   
		pshs  d 
		pshs  u 
		lbsr  ftell 
		leas  2,s 
		ldd   2,x 
		pshs  d 
		ldd   ,x 
		pshs  d 
		ldd   8,u 
		pshs  d 
		lbsr  __os_seek 
		leas  8,s 
L012c 	ldd   ,u 
		subd  2,u 
		std   2,s 
		lbeq  L0194 
		ldd   6,u 
		anda  #1 
		lbeq  L0194 
		andb  #$40 
		beq   L016f 
		ldd   2,u 
		bra   L0167 
* BGP changed
L0146
        pshs  x				save off X (do we need to?)
     	pshs  d				put count on stack
     	leax  ,s			point x to count on stack
     	pshs  x 			push pointer
		ldd   ,u 			get address of data to write
		pshs  d 			push on stack
		ldd   8,u 			get path
		pshs  d 			push on stack
		lbsr  __os_writeln 	write it
		leas  10,s 			restore stack
		cmpd  #0			success? 
		bne   L0185 		branch if not
		ldd   2,s 
		subd  ,s 
		std   2,s 
		ldd   ,u 
		addd  ,s 
L0167	std   ,u 
		ldd   2,s 
		bne   L0146 
		bra   L0194 
L016f	pshs  x
   	 	leax  2,s 				get address of count
		pshs  x 
		ldd   2,u 
		pshs  d 
		leax   8,u 
		pshs  x 
		lbsr  __os_write
		leas  8,s
		ldd   8,u 
		cmpd  2,s 
		beq   L0194 
L0185 	ldb   7,u 
		orb   #$20 
		stb   7,u 
		ldd   4,u 
		std   ,u 
		ldd   #-1 
		bra   L01a4 
L0194 	lda   6,u 
		ora   #1 
		sta   6,u 
		ldd   2,u 
		std   ,u 
		addd  11,u 
		std   4,u 
		clra   
		clrb   
L01a4 	leas  4,s 
 		puls  u,pc 
 	}
}
 
