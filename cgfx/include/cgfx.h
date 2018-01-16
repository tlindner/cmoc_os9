#include <io.h>

/**** TEXT FUNCTIONS ****/

error_code _cgfx_curhome(path_id path);

error_code _cgfx_curon(path_id path);

error_code _cgfx_curoff(path_id path);

error_code _cgfx_curlft(path_id path);

error_code _cgfx_currght(path_id path);

error_code _cgfx_curup(path_id path);

error_code _cgfx_curdwn(path_id path);

error_code _cgfx_erline(path_id path);

error_code _cgfx_ereoline(path_id path);

error_code _cgfx_ereoscrn(path_id path);

error_code _cgfx_clear(path_id path);

error_code _cgfx_bell(path_id path);

error_code _cgfx_crrtn(path_id path);

error_code _cgfx_revon(path_id path);

error_code _cgfx_revoff(path_id path);

error_code _cgfx_undlnon(path_id path);

error_code _cgfx_undlnoff(path_id path);

error_code _cgfx_blnkon(path_id path);

error_code _cgfx_blnkoff(path_id path);

error_code _cgfx_insline(path_id path);

error_code _cgfx_delline(path_id path);

error_code _cgfx_curxy(path_id path, int x, int y);


/**** CONFIGURATION FUNCTIONS ****/

error_code _cgfx_pset(path_id path, int grpnum, int bufnum);

error_code _cgfx_lset(path_id path, int grpnum, int bufnum);

error_code _cgfx_defcolr(path_id path);

error_code _cgfx_palette(path_id path, int prn, int colno);

error_code _cgfx_fcolor(path_id path, int prn);

error_code _cgfx_bcolor(path_id path, int prn);

error_code _cgfx_border(path_id path, int brn);

error_code _cgfx_scalesw(path_id path, int bsw);

error_code _cgfx_setgc(path_id path, int grpnum, int bufnum);


/**** WINDOW FUNCTIONS ****/

error_code _cgfx_dwset(path_id path, int sty, int cpx, int cpy, int szx, int szy, int fprn, int bprn, int bdprn);

error_code _cgfx_dwend(path_id path);

error_code _cgfx_dwprotsw(path_id path);

error_code _cgfx_owset(path_id path, int svs, int cpx, int cpy, int szx, int szy, int fprn, int bprn);

error_code _cgfx_mvowend(path_id path);

error_code _cgfx_owend(path_id path);

error_code _cgfx_select(path_id path);

error_code _cgfx_cwarea(path_id path);


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
