#ifndef _DEBUG_H
#define _DEBUG_H

/* Print msg and wait for enter */
void PAUSE(void);
/* Long Pring heX */
void LPX(long);
/* Debugging aid: Print useful cpu regs and wait for Enter */
void DEBUG(void);

/*
BREAK is a pseudo opcode in Mame that causes it to stop the running
emulation and bring up the Mame debugger.  It requires a patch to Mame.  If
mame is unpatched it will be considered an invalid instruction:

Patch for recent versions of Mame:
http://www.ocs.net/~n6il/mame/

The patch is derived from:
https://github.com/milliluk/mame
*/
#define BREAK asm{ fdb $113e }

#endif
