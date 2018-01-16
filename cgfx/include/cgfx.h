#include <io.h>

/**** TEXT FUNCTIONS ****/

/**
 * @brief Home the text cursor.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_curhome(path_id path);

/**
 * @brief Turn on the text cursor.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_curon(path_id path);

/**
 * @brief Turn off the text cursor.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_curoff(path_id path);

/**
 * @brief Move the text cursor left.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_curlft(path_id path);

/**
 * @brief Move the text cursor right.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_currght(path_id path);

/**
 * @brief Move the text cursor up.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_curup(path_id path);

/**
 * @brief Move the text cursor down.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_curdwn(path_id path);

/**
 * @brief Erase the line the text cursor is on.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_erline(path_id path);

/**
 * @brief Erase from the text cursor to the end of the line.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_ereoline(path_id path);

/**
 * @brief Erase from the text cursor to the end of the screen.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_ereoscrn(path_id path);

/**
 * @brief Clear the screen and home the text cursor.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_clear(path_id path);

/**
 * @brief Play the system bell sound.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_bell(path_id path);

/**
 * @brief Write a carriage return.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_crrtn(path_id path);

/**
 * @brief Turn on reverse text highlighting.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_revon(path_id path);

/**
 * @brief Turn off reverse text highlighting.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_revoff(path_id path);

/**
 * @brief Turn on text underlining.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_undlnon(path_id path);

/**
 * @brief Turn off text underlining.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_undlnoff(path_id path);

/**
 * @brief Turn on text blinking.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_blnkon(path_id path);

/**
 * @brief Turn on text blinking.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_blnkoff(path_id path);

/**
 * @brief Insert a blank line at the text cursor's line.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_insline(path_id path);

/**
 * @brief Delete the contents of the line at the text cursor's line.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_delline(path_id path);

/**
 * @brief Position the text cursor at the X and Y coordinates on the screen.
 *
 * @param path_id The path to the window device.
 * @param x The X coordinate to position the text cursor.
 * @param y The Y coordinate to position the text cursor.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_curxy(path_id path, int x, int y);


/**** BUFFER FUNCTIONS ****/

/* buffer group numbers */
#define GRP_FONT 200 /* Font group */
#define GRP_CLIP 201 /* Clipboard group (usage not standardized) */
#define GRP_PTR 202 /* Pointer group */
#define GRP_PAT2 203 /* Two color patterns */
#define GRP_PAT4 204 /* Four color patterns */
#define GRP_PAT6 205 /* Sixteen color patterns */

/* font buffers */
#define FNT_S8X8 1 /* Standard 8x8 font (default) */
#define FNT_S6X8 2 /* Standard 6x8 font */
#define FNT_G8X8 3 /* Standard graphics character font */

/* mouse pointer buffers */
#define PTR_ARR 1 /* Arrow */
#define PTR_PEN 2 /* Pencil */
#define PTR_LCH 3 /* Large Cross Hairs */
#define PTR_SLP 4 /* Hourglass (sleep) */
#define PTR_ILL 5 /* Illegal (circle with a slash) */
#define PTR_TXT 6 /* Text */
#define PTR_SCH 7 /* Small Cross Hairs */

/* pattern buffers */
#define PAT_SLD 0 /* Solid (default) */
#define PAT_DOT 1 /* Dots */
#define PAT_VRT 2 /* Vertical lines */
#define PAT_HRZ 3 /* Horizontal lines */
#define PAT_XHTC 4 /* Crosshatch */
#define PAT_LSNT 5 /* Left slanted lines */
#define PAT_RSNT 6 /* Right slanted lines */
#define PAT_SDOT 7 /* Small dots */
#define PAT_BDOT 8 /* BIG dots */

/* logic modes */
#define LOG_NONE 0 /* no logic - just put it there (default) */
#define LOG_AND 1  /* AND the contents of the screen with the data */
#define LOG_OR 2   /* OR the contents of the screen with the data */
#define LOG_XOR 3  /* XOR the contents of the screen with the data */

/* special characters for font FNT_G8X8 */
#define CHR_RGT 0xc1 /* right arrow */
#define CHR_LFT 0xc2 /* left arrow */
#define CHR_DN 0xc3  /* down arrow */
#define CHR_UP 0xc4  /* up arrow */
#define CHR_TRI 0xc5 /* triple bar (for title bar) */
#define CHR_RSZ 0xc6 /* resize box (not used) */
#define CHR_CLZ 0xc7 /* close box */
#define CHR_MOV 0xc8 /* move box */
#define CHR_VBX 0xc9 /* vertical box (for scroll markers) */
#define CHR_HBX 0xca /* horizontal box (for scroll markers) */
#define CHR_HRG 0xcb /* hourglass (Tandy menu) */
#define CHR_TRR 0xcc /* triple bar with open right side */
#define CHR_TRL 0xcd /* triple bar with open left side */

/**
 * @brief Set the drawing pattern to be used.
 *
 * @param path_id The path to the window device.
 * @param grpnum The group number.
 * @param bufnum The buffer number.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_pset(path_id path, int grpnum, int bufnum);

/**
 * @brief Set the logic point for the window.
 *
 * @param path_id The path to the window device.
 * @param lfag The logic mode.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_lset(path_id path, int mode);

/**
 * @brief Restore the default palette settings for the window.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_defcolr(path_id path);

/**
 * @brief Set the palette register to a color number.
 *
 * @param path_id The path to the window device.
 * @param prn The palette register number (0 - 15).
 * @param colno The color number (least significant 6 bits: X-X-R-G-B-R-G-B).
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_palette(path_id path, int prn, int colno);

/**
 * @brief Set the foreground color to the palette register.
 *
 * @param path_id The path to the window device.
 * @param prn The palette register number (0 - 15).
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_fcolor(path_id path, int prn);

/**
 * @brief Set the background color to the palette register.
 *
 * @param path_id The path to the window device.
 * @param prn The palette register number (0 - 15).
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_bcolor(path_id path, int prn);

/**
 * @brief Set the border color to the palette register.
 *
 * @param path_id The path to the window device.
 * @param prn The palette register number (0 - 15).
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_border(path_id path, int brn);

/**
 * @brief Toggle the scale switch for the window.
 *
 * @param path_id The path to the window device.
 * @param bsw The binary switch (0/1).
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_scalesw(path_id path, int bsw);

/**
 * @brief Set the graphic cursor for the window.
 *
 * @param path_id The path to the window device.
 * @param grpnum The group number.
 * @param bufnum The buffer number.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_setgc(path_id path, int grpnum, int bufnum);


/**** WINDOW FUNCTIONS ****/

/**
 * @brief Set the window to a type, size, and color.
 *
 * @param path_id The path to the window device.
 * @param sty The window type.
 * @param cpx The upper left window X coordinate in characters.
 * @param cpy The upper left window Y coordinate in characters.
 * @param szx The window width in characters.
 * @param szy The window height in characters.
 * @param fprn The foreground palette register.
 * @param bprn The background palette register.
 * @param bdprn The border palette register.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_dwset(path_id path, int sty, int cpx, int cpy, int szx, int szy, int fprn, int bprn, int bdprn);

/**
 * @brief End the window.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_dwend(path_id path);

/**
 * @brief Toggle window creation ability.
 *
 * @param path_id The path to the window device.
 * @param bsw The binary swtich (0/1).
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_dwprotsw(path_id path, int bsw);

/**
 * @brief Create an overlay window with a type, size, and color.
 *
 * @param path_id The path to the window device.
 * @param svs The window creation flag.
 * @param cpx The upper left window X coordinate in characters.
 * @param cpy The upper left window Y coordinate in characters.
 * @param szx The window width in characters.
 * @param szy The window height in characters.
 * @param fprn The foreground palette register.
 * @param bprn The background palette register.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_owset(path_id path, int svs, int cpx, int cpy, int szx, int szy, int fprn, int bprn);

/**
 * @brief End a Multi-Vue type overlay window.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_mvowend(path_id path);

/**
 * @brief End an overlay window.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_owend(path_id path);

/**
 * @brief Select a window.
 *
 * @param path_id The path to the window device.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_select(path_id path);

/**
 * @brief Change the working area of a window.
 *
 * @param path_id The path to the window device.
 * @param cpx The new upper left window X coordinate in characters.
 * @param cpy The new upper left window Y coordinate in characters.
 * @param szx The new window width in characters.
 * @param szy The new window height in characters.
 * @return 0 if successful, otherwise the error code.
 */
error_code _cgfx_cwarea(path_id path, int cpx, int cpy, int szx, int szy);


/**** DRAW FUNCTIONS ****/

error_code _cgfx_setdptr(path_id path, int x, int y);

error_code _cgfx_rsetdptr(path_id path, int xo, int yo);

error_code _cgfx_point(path_id path, int x, int y);

error_code _cgfx_rpoint(path_id path, int xo, int yo);

error_code _cgfx_line(path_id path, int x, int y);

error_code _cgfx_rline(path_id path, int xo, int yo);

error_code _cgfx_linem(path_id path, int x, int y);

error_code _cgfx_rlinem(path_id path, int xo, int yo);

error_code _cgfx_box(path_id path, int x, int y);

error_code _cgfx_rbox(path_id path, int xo, int yo);

error_code _cgfx_bar(path_id path, int x, int y);

error_code _cgfx_rbar(path_id path, int xo, int yo);

error_code _cgfx_ffill(path_id path);

error_code _cgfx_circle(path_id path, int radius);

error_code _cgfx_ellipse(path_id path, int xrad, int yrad);

error_code _cgfx_putgc(path_id path, int x, int y);

error_code _cgfx_arc(path_id path, int xrad, int yrad, int xo1, int yo1, int xo2, int yo2);


/**** FONT FUNCTIONS ****/

error_code _cgfx_font(path_id path, int grp, int buf);

error_code _cgfx_tcharsw(path_id path, int sw);

error_code _cgfx_boldsw(path_id path, int sw);

error_code _cgfx_propsw(path_id path, int sw);



/* definitions for _os_gs_keysense() bits */
#define	_SS_KEYSENSE_SHIFT	(1<<0)
#define	_SS_KEYSENSE_CTRL	(1<<1)
#define	_SS_KEYSENSE_ALT	(1<<2)
#define	_SS_KEYSENSE_UP		(1<<3)
#define	_SS_KEYSENSE_DOWN	(1<<4)
#define	_SS_KEYSENSE_LEFT	(1<<5)
#define	_SS_KEYSENSE_RIGHT	(1<<6)
#define	_SS_KEYSENSE_SPACE	(1<<7)

error_code _os_gs_keysense(path_id path, int *keys);

error_code _os_ss_keysense(path_id path, int flag);

error_code _cgfx_ss_tone(path_id path, int duration, int volume, int frequency);



/**** MOUSE FUNCTIONS ****/

/* structure for reading mouse info packet */
typedef struct mousin {
 char pt_valid,  /* is info valid? */
      pt_actv,   /* active side */
      pt_totm,   /* timeout initial value */
      pt_rsrv0[2],/* reserved */
      pt_tto,    /* time till timeout */
      pt_tsst[2],/* time since start counter */
      pt_cbsa,   /* current button state button A */
      pt_cbsb,   /* current button state button B */
      pt_ccta,   /* click count button A */
      pt_cctb,   /* click count button B */
      pt_ttsa,   /* time this state button A */
      pt_ttsb,   /* time this state button B */
      pt_tlsa,   /* time last state button A */
      pt_tlsb,   /* time last state button B */ 
      pt_rsrv1[6],/* reserved */
      pt_stat,   /* window pointer location type */
      pt_res;    /* resolution */
 int  pt_acx,    /* actual x value */
      pt_acy,    /* actual y value */
      pt_wrx,    /* window relative x value */
      pt_wry;    /* window relative y value */
} MSRET;

/* window regions for mouse */
#define WR_CNTNT	0 /* content region */
#define WR_CNTRL	1 /* control region */
#define WR_OFWIN	2 /* off window */
      
error_code _cgfx_ss_mouse(path_id path, int sample_rate, int timeout, int autofollow);

error_code _cgfx_ss_mssig(path_id path, int signo);

error_code _cgfx_gs_mouse(path_id path, void *mpkt, int port);

error_code _cgfx_mousexy(path_id path, int *x, int *y);


/**** BUFFER FUNCTIONS ****/

error_code _cgfx_dfngpbuf(path_id path, int grp, int buf, int bl);

error_code _cgfx_kilbuf(path_id path, int grp, int buf);

error_code _cgfx_gpload(path_id path, int grp, int buf, int sty, int sx, int sy, int bl);

error_code _cgfx_getblk(path_id path, int grp, int buf, int bx, int by, int sx, int sy);

error_code _cgfx_putblk(path_id path, int grp, int buf, int bx, int by);


/**** MULTI-VUE FUNCTIONS ****/

#define MNENBL 		1
#define MNDSBL 		0
#define WINSYNC 	0xc0c0

/* default menu id's */
#define MN_MOVE 	1
#define MN_CLOS 	2
#define MN_GROW 	3
#define MN_USCRL 	4
#define MN_DSCRL 	5
#define MN_RSCRL 	6
#define MN_LSCRL 	7
#define MN_TNDY 	20
#define MN_FILE 	21
#define MN_EDIT 	22
#define MN_STYL 	23
#define MN_FONT 	24

/* window - menu data structures */
typedef struct mistr {  /* menu item descriptor */
	char _mittl[15];       /* name of item */
	char _mienbl;          /* is item available? */
	char _mires[5];        /* reserved */
} MIDSCR;              /* item descriptor */

typedef struct mnstr {
	char _mnttl[15];       /* name of menu */
	char _mnid,            /* menu id number */
		_mnxsiz,          /* width of menu */
		_mnnits,          /* number of items */
		_mnenabl;         /* is menu available? */
	char _mnres[2];        /* reserved bytes */
	struct mistr* _mnitems; /* pointer to items */
} MNDSCR;              /* menu descriptor */

typedef struct wnstr {  /* window descriptor */
	char _wnttl[20];       /* title of window */
	char _nmens;           /* number of menus on window */
	char _wxmin,           /* min. window width */
		_wymin;           /* min. window height */
	short _wnsync;         /* synch bytes $C0C0 */
	char _wnres[7];        /* reserved */
	struct mnstr* _wnmen;  /* pointer to menu descriptor's array */
} WNDSCR;

error_code _cgfx_ss_wnset(path_id path, int wintype, WNDSCR *windat);

error_code _cgfx_gs_mnsel(path_id path, int *itemno);

error_code _cgfx_ss_umbar(path_id path);

error_code _cgfx_ss_sbar(path_id path, int horbar, int verbar);


/**** STATUS FUNCTIONS ****/

error_code _cgfx_gs_crsr(path_id path, int *x, int *y);
 
error_code _cgfx_gs_scsz(path_id path, int *x, int *y);

error_code _cgfx_gs_palt(path_id path, char *palbuf);

error_code _cgfx_ss_mgpb(path_id path, int grpnum, int bufnum, int mapflag, int *size, char *bufaddr);

error_code _cgfx_gs_styp(path_id path, int *type);

error_code _cgfx_gs_fbrg(path_id path, int *fore, int *back, int *bord);

error_code _cgfx_ss_gip(path_id path, int msres, int msport, int kbdstrt, int kbdrpt);

error_code _cgfx_ss_dfpl(path_id path, char *palbuf);

error_code _cgfx_ss_mtyp(path_id path, int montype);
