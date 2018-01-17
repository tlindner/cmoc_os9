# Makefile to create assembler library
#include $(NITROS9DIR)/rules.mak

MEM = mem.o memory.o memchr.o memccpy.o memcmp.o memset.o memcpy.o memchr.o
SYS = sleep.o
MISC = rpterr.o cfinish.o tidyup.o chcodes.o htoi.o htol.o #rand.o
MATH_SUPPORT = ccmult.o ccdiv.o ccmod.o atoi.o abs.o
FLOAT_SUPPORT = fcommon.o cfloats.o atof.o scale.o
LONG_SUPPORT = clcommon.o clcompare.o clconvert.o claddsub.o clbits.o cldiv.o clmove.o clnegcompl.o clincdec.o clmul.o clshifts.o atol.o
FILE_SUPPORT = attr.o io.o
MODS = $(MEM) $(SYS) $(MISC) $(MATH_SUPPORT) $(FLOAT_SUPPORT) $(LONG_SUPPORT) $(FILE_SUPPORT) time.o syscall.o syscommon.o
CC = cmoc
ASM = lwasm
CFLAGS = -I../include
ASOUT = --obj -o

%.o: %.as
	$(ASM) $(AFLAGS) $< $(ASOUT)$@

all:	libc.a

libc.a: $(MODS)
	lwar -c $@ $(MODS)

dskclean: clean

clean:
	$(RM) *.o libc.a
