/*
 * os.h - OS-9/NitrOS-9 Definitions
 */

#include <cmoc.h>

extern int errno;

typedef int error_code;

/* These probably need to go into cmoc.h */
typedef unsigned char byte;
typedef byte BOOL;

/* System calls */
#define F$ID		0x0C
#define F$Time		0x15
#define F$STime		0x16


/* I/O system calls */
#define	I$Attach	0x80
#define	I$Detach	0x81
#define	I$Dup		0x82
#define	I$Create	0x83
#define	I$Open		0x84
#define	I$MakDir	0x85
#define	I$ChgDir	0x86
#define	I$Delete	0x87
#define	I$Seek		0x88
#define	I$Read		0x89
#define	I$Write		0x8A
#define	I$ReadLn	0x8B
#define	I$WritLn	0x8C
#define	I$GetStt	0x8D
#define	I$SetStt	0x8E
#define	I$Close		0x8F
#define	I$DeletX	0x90

/* Error codes */
#define	E$Seek		0xF7

/* GetStat/SetStat calls */
#define	SS_Size		0x02
#define	SS_Pos		0x05
#define	SS_FD		0x0F


typedef struct _registers_6809 {
    char cc, a, b, dp;
    int  x, y, u, s;
} registers_6809;

error_code _os_syscall(int callcode, registers_6809 *registers);
