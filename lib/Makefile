# Makefile to create assembler library
vpath %.asm $(HOME)/Projects/cmoc-0.1.46b/src/stdlib

CMOC = addDWordDWord.o addDWordInt.o addDWordUnsignedInt.o addIntDWord.o addUnsignedIntDWord.o andDWordDWord.o andDWordWord.o cmpDWordDWord.o cmpDWordSignedInt.o cmpDWordUnsignedInt.o cmpSignedIntDWord.o cmpUnsignedIntDWord.o copyDWord.o copyDWordFromXToD.o copyWordToDWord.o decrementDWord.o divDWordDWord.o divDWordUnsignedInt.o divModDWordDWord.o divModDWordUnsignedInt.o divModUnsignedIntDWord.o divUnsignedIntDWord.o incrementDWord.o initByteFromDWord.o initDWordFromSignedWord.o initDWordFromUnsignedWord.o initWordFromDWord.o isDWordZero.o leftShiftDWord.o leftShiftDWordAtXByB.o modDWordDWord.o modDWordUnsignedInt.o modUnsignedIntDWord.o mulDWordDWord.o mulDWordInt.o mulDWordUnsignedInt.o mulIntDWord.o mulUnsignedIntDWord.o negateDWord.o orDWordDWord.o orDWordWord.o rightShiftDWord.o rightShiftDWordAtXByB.o signExtWordToDWord.o signedDivDWordDWord.o subDWordDWord.o subDWordInt.o subDWordUnsignedInt.o subIntDWord.o subUnsignedIntDWord.o testAndRemoveSignOnDWord.o xorDWordDWord.o xorDWordWord.o DIV16.o DIV16BY10.o MUL16.o MUL168_TO24.o MUL168_TO32.o SDIV16.o shiftByteLeft.o shiftByteRightSigned.o shiftByteRightUnsigned.o shiftLeft.o shiftRightSigned.o shiftRightUnsigned.o jumpTableSwitch.o
STRING = strlen.o
MEM = mem.o memory.o memchr.o memccpy.o memcmp.o memset.o memcpy.o memchr.o
SYS = sleep.o
IO = printf.o pffinit.o pflinit.o pfldummy.o putc.o iob_data.o setbase.o fseek.o fopen.o
LOW_IO = access.o create.o open.o read.o write.o
MISC = rpterr.o chcodes.o htoi.o htol.o rand.o prof.o
MATH_SUPPORT = ccmult.o ccdiv.o ccmod.o atoi.o abs.o
FLOAT_SUPPORT = fcommon.o cfloats.o atof.o scale.o
LONG_SUPPORT = clcommon.o clcompare.o clconvert.o claddsub.o clbits.o cldiv.o clmove.o clnegcompl.o clincdec.o clmul.o clshifts.o atol.o
FILE_SUPPORT = attr.o io.o
OS = stat.o id.o mod.o process.o cfinish.o tidyup.o
MODS = $(CMOC) $(STRING) $(OS) $(IO) $(LOW_IO) $(MEM) $(SYS) $(MISC) $(MATH_SUPPORT) $(FLOAT_SUPPORT) $(LONG_SUPPORT) $(FILE_SUPPORT) time.o syscall.o syscommon.o
CC = cmoc
ASM = lwasm
CFLAGS = -I../include
ASOUT = --obj -o

%.o: %.as
	$(ASM) $(AFLAGS) $< $(ASOUT)$@

%.o: %.asm
	$(ASM) $(AFLAGS) $< $(ASOUT)$@

all:	libc.a

libc.a: $(MODS)
	lwar -c $@ $(MODS)

dskclean: clean

clean:
	$(RM) *.o libc.a
