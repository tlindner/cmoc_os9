#include <io.h>

/* text routines */
void _cgfx_curhome(path_id path);

void _cgfx_curon(path_id path);

void _cgfx_curoff(path_id path);

void _cgfx_curlft(path_id path);

void _cgfx_currght(path_id path);

void _cgfx_curup(path_id path);

void _cgfx_curdwn(path_id path);

void _cgfx_erline(path_id path);

void _cgfx_ereoline(path_id path);

void _cgfx_ereoscrn(path_id path);

void _cgfx_clear(path_id path);

void _cgfx_bell(path_id path);

void _cgfx_crrtn(path_id path);

void _cgfx_revon(path_id path);

void _cgfx_revoff(path_id path);

void _cgfx_undlnon(path_id path);

void _cgfx_undlnoff(path_id path);

void _cgfx_blnkon(path_id path);

void _cgfx_blnkoff(path_id path);

void _cgfx_insline(path_id path);

void _cgfx_delline(path_id path);

void _cgfx_curxy(path_id path, int x, int y);


/* configuration routines */
void _cgfx_pset(path_id path, int grpnum, int bufnum);

void _cgfx_lset(path_id path, int grpnum, int bufnum);

void _cgfx_defcolr(path_id path);

void _cgfx_palette(path_id path, int prn, int colno);

void _cgfx_fcolor(path_id path, int prn);

void _cgfx_bcolor(path_id path, int prn);

void _cgfx_border(path_id path, int brn);

void _cgfx_scalesw(path_id path, int bsw);

void _cgfx_setgc(path_id path, int grpnum, int bufnum);


/* window routines */
void _cgfx_dwset(path_id path, int sty, int cpx, int cpy, int szx, int szy, int fprn, int bprn, int bdprn);

void _cgfx_dwend(path_id path);

void _cgfx_dwprotsw(path_id path);

void _cgfx_owset(path_id path, int svs, int cpx, int cpy, int szx, int szy, int fprn, int bprn);

void _cgfx_mvowend(path_id path);

void _cgfx_owend(path_id path);

void _cgfx_select(path_id path);

void _cgfx_cwarea(path_id path);


/* draw routines */
void _cgfx_setdptr(path_id path, int x, int y);

void _cgfx_rsetdptr(path_id path, int xo, int yo);

void _cgfx_point(path_id path, int x, int y);

void _cgfx_rpoint(path_id path, int xo, int yo);

void _cgfx_line(path_id path, int x, int y);

void _cgfx_rline(path_id path, int xo, int yo);

void _cgfx_linem(path_id path, int x, int y);

void _cgfx_rlinem(path_id path, int xo, int yo);

void _cgfx_box(path_id path, int x, int y);

void _cgfx_rbox(path_id path, int xo, int yo);

void _cgfx_bar(path_id path, int x, int y);

void _cgfx_rbar(path_id path, int xo, int yo);

void _cgfx_ffill(path_id path);

void _cgfx_circle(path_id path, int radius);

void _cgfx_ellipse(path_id path, int xrad, int yrad);

void _cgfx_putgc(path_id path, int x, int y);

void _cgfx_arc(path_id path, int xrad, int yrad, int xo1, int yo1, int xo2, int yo2);
