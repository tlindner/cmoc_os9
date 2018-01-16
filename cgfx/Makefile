# Makefile to create assembler library
#include $(NITROS9DIR)/rules.mak

MODS = window.o cbuffer.o
CC = cmoc
ASM = lwasm
CFLAGS = -I../include
ASOUT = --obj -o

%.o: %.as
	$(ASM) $(AFLAGS) $< $(ASOUT)$@

all:	libcgfx.a

libcgfx.a: $(MODS)
	lwar -c $@ $(MODS)

dskclean: clean

clean:
	$(RM) *.o libcgfx.a
