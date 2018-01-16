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
#define	I$Attach	    0x80
#define	I$Detach	    0x81
#define	I$Dup		    0x82
#define	I$Create	    0x83
#define	I$Open		    0x84
#define	I$MakDir	    0x85
#define	I$ChgDir	    0x86
#define	I$Delete	    0x87
#define	I$Seek		    0x88
#define	I$Read		    0x89
#define	I$Write		    0x8A
#define	I$ReadLn	    0x8B
#define	I$WritLn	    0x8C
#define	I$GetStt	    0x8D
#define	I$SetStt	    0x8E
#define	I$Close		    0x8F
#define	I$DeletX	    0x90

/* Error codes */
#define	E$PthFul        0xC8
#define	E$BPNum         0xC9
#define	E$Poll          0xCA
#define	E$BMode         0xCB
#define	E$DevOvf        0xCC
#define	E$BMID          0xCD
#define	E$DirFul        0xCE
#define	E$MemFul        0xCF
#define	E$UnkSvc        0xD0
#define	E$ModBsy        0xD1
#define	E$BPAddr        0xD2
#define	E$EOF           0xD3
#define	E$NES           0xD5
#define	E$FNA           0xD6
#define	E$BPNam         0xD7
#define	E$PNNF          0xD8
#define	E$SLF           0xD9
#define	E$CEF           0xDA
#define	E$IBA           0xDB
#define	E$HangUp        0xDC
#define	E$MNF           0xDD
#define	E$DelSP         0xDF
#define	E$IPrcID        0xE0
#define	E$BPrcID        E$IPrcID
#define	E$NoChld        0xE2
#define	E$ISWI          0xE3
#define	E$PrcAbt        0xE4
#define	E$PrcFul        0xE5
#define	E$IForkP        0xE6
#define	E$KwnMod        0xE7
#define	E$BMCRC         0xE8
#define	E$USigP         0xE9
#define	E$NEMod         0xEA
#define	E$BNam          0xEB
#define	E$BMHP          0xEC
#define	E$NoRAM         0xED
#define	E$DNE           0xEE
#define	E$NoTask        0xEF
#define	E$Unit          0xF0
#define	E$Sect          0xF1
#define	E$WP            0xF2
#define	E$CRC           0xF3
#define	E$Read          0xF4
#define	E$Write         0xF5
#define	E$NotRdy        0xF6
#define	E$Seek          0xF7
#define	E$Full          0xF8
#define	E$BTyp          0xF9
#define	E$DevBsy        0xFA
#define	E$DIDC          0xFB
#define	E$Lock          0xFC
#define	E$Share         0xFD
#define	E$DeadLk        0xFE

/* GetStat/SetStat calls */
#define	SS_Size		    0x02
#define	SS_Pos		    0x05
#define	SS_FD		    0x0F


typedef struct _registers_6809 {
    char cc, a, b, dp;
    int  x, y, u, s;
} registers_6809;

error_code _os_syscall(int callcode, registers_6809 *registers);
