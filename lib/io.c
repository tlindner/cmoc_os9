#include "io.h"


asm int
_os_create(char *pathname, int mode, path_id *path, int perm)
{
	asm
    {
_os9err EXTERN
_sysret EXTERN
* stack:
*	0,s = return address
*	2,s = pathname pointer
*	4,s = mode
*	6,s = path pointer [out]
*	8,s = permissions
		ldx 	2,s 		get pointer to pathname
		lda   	8+1,s 	get permissions byte
		tfr   	a,b 
		andb	#$24 
		orb 	#$0b 
		os9		I$Create 
		bcc 	createok 
		cmpb	#$da 
		bne		createerr 
		lda		4+1,s 		get mode
		bita	#$80 
		bne		createerr 
		anda	#7 
		ldx 	2,s 		get pointer to pathname
		os9		I$Open 
		bcs 	createerr 
		pshs	d		save off path number
		tfr		a,b
		clra
		std		[6+2,s]
		puls	d
		pshs	a,u 
		ldx		#0 
		leau	,x 
		ldb 	#2 
		os9		I$SetStt 
		puls	a,u 
		bcc		createok 
		pshs	b 
		os9		I$Close 
		puls	b 
createerr
		lbra	_os9err 
createok
		tfr		a,b
		clra
		std		[6,s]
		lbra	_sysret
    }
}


asm error_code
_os_open(char *pathname, int mode, path_id *path)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = pathname pointer
*	4,s = mode
*	6,s = path pointer [out]
		ldx  	2,s 			; get pathname pointer
		lda		5,s				; get mode 
		os9		I$Open 
		lblo	_os9err
		pshs	d
		tfr		a,b
		clra
		std		[6+2,s]
		puls	d
		lbra	_sysret
    }
}


asm error_code
_os_close(path_id path)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = path
        lda     3,s             ; get path
        os9     I$Close
        lbra	_sysret
    }
}


asm error_code
_os_delete(char *pathname, int mode)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = pathname pointer
*	4,s = mode
        ldx     2,s             ; get pathname pointer
        lda     5,s             ; get mode
        os9     I$DeletX
        lbra	_sysret
    }
}


asm error_code
_os_makdir(char *pathname, int perm)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = pathname pointer
*	4,s = permissions
        ldx     2,s             ; get pathname pointer
        ldb     5,s             ; get permissions
        os9     I$MakDir
        lbra	_sysret
    }
}


asm error_code
_os_read(path_id path, void *data, int *count)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = path
*	4,s = data pointer
*	6,s = count pointer [in/out]
		pshs		y 
		lda			3+2,s	 		path
		ldx			4+2,s			pointer to data 
		ldy			[6+2,s] 		count
		pshs		y 
		os9			I$Read 
afterread
		bcc			savecount
		cmpb		#$d3 E$EOF?
		bne			readerr
		ldy			#0000   
		bra			savecount   
readerr	puls		x,y 
		lbra		_os9err 
savecount sty		[6+4,s]
		puls		x,y 
		lbra		_sysret
    }
}

asm error_code
_os_readln(path_id path, void *data, int *count)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = path
*	4,s = data pointer
*	6,s = count pointer [in/out]
		pshs		y 
		lda			3+2,s 
		ldx			4+2,s 
		ldy			[6+2,s]
		pshs		y 
		os9			I$ReadLn 
		bra			afterread 
	}
}

asm error_code
_os_write(path_id path, void *data, int *count)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = path
*	4,s = data pointer
*	6,s = count pointer [in/out]
		pshs		y 
		ldy			[6+2,s]		get length
		beq			writeex		if zero, nothing to do
		lda			3+2,s		get path
		ldx			4+2,s		get data pointer
		os9			I$Write
L00xe	bcc			store_writeex 
		puls		y 
		lbra		_os9err 
store_writeex
		sty			[6+2,s]
writeex
		puls		y
		lbra		_sysret
	}
}

asm error_code
_os_writeln(path_id path, void *data, int *count)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = path
*	4,s = data pointer
*	6,s = count pointer [in/out]
		pshs		y
		ldy			[6+2,s]			get length
		beq			writeex			if zero, nothing to do 
		lda 		3+2,s 			get path
		ldx 		4+2,s 			get data pointer
		os9			I$WritLn 
		bra			L00xe 
	}
}

asm error_code
_os_seek(path_id path, long position)
{
    asm
    {
* stack:
*	0,s = return address
*	2,s = path
*	4,s = 32-bit position
		lda			3,s
		pshs 		u
		ldx			4+2,s
		ldu			4+2+2,s
		os9			I$Seek 
		puls		u
		lbra		_sysret
	}
}
