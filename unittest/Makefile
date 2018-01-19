CC = cmoc
OS9FLAGS = --os9
OPT = -O2
LFLAGS = -I../include -I../cgfx/include $(OS9FLAGS)

%: %.c
	$(CC) $(LFLAGS) $^ $(OBJS) -L../lib -lc -L../cgfx -lcgfx


TESTS	= timetest fiotest iotest syscalltest memtest wintest floattest maze

all:	$(TESTS)

dsk:	all
	os9 format -e -q -ds -dd -t80 test.dsk
	os9 makdir test.dsk,CMDS
	os9 copy iotest test.dsk,CMDS
	os9 attr test.dsk,CMDS/iotest -epe
	os9 copy fiotest test.dsk,CMDS
	os9 attr test.dsk,CMDS/fiotest -epe
	os9 copy timetest test.dsk,CMDS
	os9 attr test.dsk,CMDS/timetest -epe
	os9 copy syscalltest test.dsk,CMDS
	os9 attr test.dsk,CMDS/syscalltest -epe
	os9 copy memtest test.dsk,CMDS
	os9 attr test.dsk,CMDS/memtest -epe
	os9 copy wintest test.dsk,CMDS
	os9 attr test.dsk,CMDS/wintest -epe
	os9 copy maze test.dsk,CMDS
	os9 attr test.dsk,CMDS/maze -epe
	os9 copy floattest test.dsk,CMDS
	os9 attr test.dsk,CMDS/floattest -epe
	echo "chx /d1/cmds; chd /d1" > go
	echo "iotest" >> go
	echo "timetest" >> go
	echo "syscalltest" >> go
	echo "memtest" >> go
	echo "wintest" >> go
	os9 copy -l go test.dsk,


run:	dsk
	mame64 -inipath ~/Documents/mame -video opengl -window coco3 -flop1 $(NITROS9DIR)/level2/coco3/NOS9_6809_L2_v030300_coco3_80d.dsk -flop2 test.dsk -speed 4

clean:
	-rm $(TESTS) test.dsk go
