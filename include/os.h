/*
 * os.h - OS-9/NitrOS-9 Definitions
 */

//#include <cmoc.h>

extern int errno;

typedef int error_code;

/* These probably need to go into cmoc.h */
typedef unsigned char byte;
typedef byte BOOL;

/* System calls */
#define F$Link          0x00
#define F$Load          0x01
#define F$UnLink        0x02
#define F$Fork          0x03
#define F$Wait          0x04
#define F$Chain         0x05
#define F$Exit          0x06
#define F$Mem           0x07
#define F$Send          0x08
#define F$Icpt          0x09
#define F$Sleep         0x0A
#define F$SSpd          0x0B
#define F$ID            0x0C
#define F$SPrior        0x0D
#define F$SSWI          0x0E
#define F$PErr          0x0F
#define F$PrsNam        0x10
#define F$CmpNam        0x11
#define F$SchBit        0x12
#define F$AllBit        0x13
#define F$DelBit        0x14
#define F$Time          0x15
#define F$STime         0x16
#define F$CRC           0x17

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
#define	SS_Opt          0x00
#define	SS_Ready        0x01
#define	SS_Size         0x02
#define	SS_Reset        0x03
#define	SS_WTrk         0x04
#define	SS_Pos          0x05
#define	SS_EOF          0x06
#define	SS_Link         0x07
#define	SS_ULink        0x08
#define	SS_Feed         0x09
#define	SS_Frz          0x0A
#define	SS_SPT          0x0B
#define	SS_SQD          0x0C
#define	SS_DCmd         0x0D
#define	SS_DevNm        0x0E
#define	SS_FD           0x0F
#define	SS_Ticks        0x10
#define	SS_Lock         0x11
#define	SS_DStat        0x12
#define	SS_Joy          0x13
#define	SS_BlkRd        0x14
#define	SS_BlkWr        0x15
#define	SS_Reten        0x16
#define	SS_WFM          0x17
#define	SS_RFM          0x18
#define	SS_ELog         0x19
#define	SS_SSig         0x1A
#define	SS_Relea        0x1B
#define	SS_AlfaS        0x1C
#define	SS_Attr         SS_AlfaS
#define	SS_Break        0x1D
#define	SS_RsBit        0x0E
#define	SS_FDInf        0x20
#define	SS_DirEnt       SD.FDInf
#define	SS_SetMF        0x24
#define	SS_Cursr        0x25
#define	SS_ScSiz        0x26
#define	SS_KySns        0x27
#define	SS_ComSt        0x28
#define	SS_Open         0x29
#define	SS_Close        0x2A
#define	SS_HngUp        0x2B
#define	SS_FSig         0x2C
#define	SS_DSize        SS_ScSiz
#define	SS_VarSect      SS_DStat

/* System Specific and User Defined Codes */
#define	SS_AAGBf        0x80
#define	SS_SLGBf        0x81
#define	SS_Mount        0x82
#define	SS_RdNet        0x83
#define	SS_MpGPB        0x84
#define	SS_Slots        0x85

/* Level 2 Windowing Codes */
#define	SS_WnSet        0x86	// Set up High Level Windowing Information
#define	SS_MnSel        0x87	// Request High level Menu Handler take determine next event
#define	SS_SBar         0x88	// SetStat to set position block on Window scroll bars
#define	SS_Mouse        0x89	// Return Mouse information packet (COCO)
#define	SS_MsSig        0x8A	// SetStat to tell driver to send signal on mouse event
#define	SS_AScrn        0x8B	// Allocate a screen for application poking
#define	SS_DScrn        0x8C	// Display a screen allocated by SS_AScrn
#define	SS_FScrn        0x8D	// Free a screen allocated by SS_AScrn
#define	SS_PScrn        0x8E	// Polymorph Screen into different screen type
#define	SS_ScInf        0x8F	// Get Current screen info for direct writes
#define	SS_Palet        0x91	// Return palette information
#define	SS_Montr        0x92	// Get and Set Monitor Type
#define	SS_ScTyp        0x93	// Get screen type information
#define	SS_GIP          0x94	// Global Input Parameters (SetStat)
#define	SS_UMBar        0x95	// update menu bar (SetStat)
#define	SS_FBRgs        0x96	// return color registers (GetStat)
#define	SS_DfPal        0x97	// set/return default palette registers (Getstat/Setstat)
#define	SS_Tone         0x98	// Generate a tone using 6 bit sound
#define	SS_GIP2         0x99	// Global Input Params #2 (L2V3)
#define	SS_AnPal        0x9A	// Animate palettes (L2V3)
#define	SS_FndBf        0x9B	// Find named buffer (L2V3)


error_code _os9_sleep(int *ticks);


typedef struct _registers_6809 {
    char cc, a, b, dp;
    int  x, y, u, s;
} registers_6809;

error_code _os_syscall(int callcode, registers_6809 *registers);

int abs(int value);