* Disassembly by Os9disasm of utime.r


__os_getime EXTERNAL
_flacc EXTERNAL
_sprintf EXTERNAL
_DEBUG EXTERNAL

_time EXPORT
_o2utime EXPORT
_u2otime EXPORT
_localtime EXPORT
_asctime EXPORT
_ctime EXPORT

 section bss

* Uninitialized data (class B)
_tm rmb 16
_datebuf rmb 26

 endsection

 section rwdata

*
* static int   monsiz[] = {31,28,31,30,31,30,31,31,30,31,30,31};
monsiz
 fdb 31,28,31,30,31,30,31,31,30,31,30,31

 endsect

 section code

* long
* time(arg)
* long  *arg;
*    {
*    _os_time tbuf;
*    long  result, o2utime();
*
*    getime(tbuf);
*    result = o2utime(tbuf);
*    if (arg)
*       *arg = result;
*    return (result);
*    }

* CMOC adds an hidden argument
* long time(long *return, long *arg)
*
* _os_getime
* |    _o2utime
* V    s    hidden long * to _o2utime
* s    s+2  &tbuf - arg to os_getime and o2utime
* s+2  s+4  _os_time tbuf
* s+8  s+10 saved U
* s+10 s+12 return addr
* s+12 s+14 hidden long * to _time
* s+14 s+16 long *arg

_time
 pshs  u
 leas  -6,s tbuf
 leau  ,s address of tbuf
 pshs  u
 lbsr  __os_getime get system time
 stu   ,s still &tbuf
 ldx   12,s hidden long * argument to time
 pshs  x    hidden long * argument to o2utime
 bsr   _o2utime convert unix style
 ldu   16,s check arg
 beq   noarg
 ldd   ,x so copy over
 std   ,u
 ldd   2,x
 std   2,u
noarg leas 10,s
 puls  u,pc


* long
* o2utime(tp)
* _os_time  *tp;
*    {
*    int   j, leap;
*    long  accum = 0;
*
* CMOC adds an extra parameter
* long o2utime(long *return, _os_time *tp)
_o2utime
 pshs D,U
 ldu 8,s get tp
 clra
 clrb
 pshs  d
 pshs  d

*    for (j = 70; j < *tp; ++j)         /* total up days in years past */
*       accum += ((j & 3) ? 365 : 366);     /* don't forget leap years */
 ldb   #70-1
 ldx   #0
 bra   o2ut2

o2ut1 leax  365,x
 bitb  #3
 bne   o2ut2
 leax  1,x
o2ut2 incb
 cmpb  ,u  year
 blt   o2ut1
 stx   2,s
*
*    monsiz[1] = (*tp++ & 3) ? 28 : 29;           /* fix for leap year */
 leax  monsiz,y
 lda   #29 assume leap year
 ldb   ,u+
 andb  #3
 beq   o2ut3 it is a leap year
 lda   #28
o2ut3 sta   3,x fix up February in table

*
*    for (j = 0; j < *tp; ++j)             /* add day1 for months past */
*       accum += monsiz[j];
 ldb   #1
 bra   o2ut5

o2ut4 ldd   ,x++
 addd  2,s
 std   2,s

 ldb   4,s
 incb
o2ut5 stb   4,s
 cmpb  ,u
 blt   o2ut4

*
*    ++tp;
 leau  1,u

*    accum += (*tp++ - 1);                      /* add days this month */
 ldb   ,u+
 decb
 clra
 addd  2,s
 std   2,s

*    accum *= 24;                                  /* convert to hours */
 lslb
 rola
 addd  2,s  *3
 lslb
 rola
 rol   1,s *6
 lslb
 rola
 rol   1,s *12
 lslb
 rola
 rol   1,s *24
 std   2,s

*
*    accum += *tp++;                                /* add hours today */
 ldb   ,u+
 clra
 addd  2,s
 std   2,s
 ldb   1,s
 adcb  #0
 stb   1,s

*    accum *= 60;                                /* convert to minutes */
 bsr   mul60
*
*    accum += *tp++;                              /* add minutes today */
 ldb   ,u+
 clra
 addd  2,s
 std   2,s
 ldd   ,s
 adcb  #0
 adca  #0
 std   ,s

*    accum *= 60;                                /* convert to seconds */
 bsr   mul60

*
*    accum += *tp;                                /* add seconds today */
 ldb   ,u+
 clra
 addd  2,s
 std   2,s
 ldd   ,s
 adcb  #0
 adca  #0
 std   ,s

*
* return (accum);
 leau  ,s
 ldx  10,s * leax  _flacc,y
 ldd   ,u
 std   ,x
 ldd   2,u
 std   2,x
 leas  6,s
 puls  u,pc

*    }
mul60 ldx   2,s
 ldd   4,s
 bsr   shift16
 bsr   shift16
 addd  4,s
 exg   d,x
 adcb  3,s
 adca  2,s
 exg   d,x
 stx   2,s
 std   4,s
 bsr   shift16
 addd  4,s
 exg   d,x
 adcb  3,s
 adca  2,s
 exg   d,x
 bsr   shift16
 bsr   shift16
 stx   2,s
 std   4,s
 rts

shift16 lslb
 rola
 exg   d,x
 rolb
 rola
 exg   d,x
 rts

* /*
* ** function to convert a 'tm' style time to os9 time
* */
*
* u2otime(otime, tmp)
* char        *otime
* struct tm   *tmp;
*    {
*    otime->t_year = tmp->tm_year;
*    otime->t_month = tmp->tm_mon;
*    otime->t_day   = tmp->tm_mday;
*    otime->t_hour  = tmp->tm_hour;
*    otime->t_minute = tmp->tm_min;
*    otime->t_second = tmp->tm_sec;
*    }
_u2otime
 pshs  u
 ldu   6,s *tmp
 ldx   4,s *otime
 leax  6,x get to end
 lda   #6 bytes to copy
u2o1 ldb   ,u+ dummy
 ldb   ,u+ get data
 stb   ,-x stash away
 deca
 bne   u2o1
 puls  u,pc

daylight fdb 0
timezone fdb 0,0
*
* struct tm *
* localtime(utime)
* long  *utime;
*    {
*    register struct tm *tmp = &_tm;
*    long  ticks = *utime;
*    int   days;
*    int   fac;
*
_localtime
 pshs  d,u save U and allocate some scratch
 leau  _tm,y

*    tmp->tm_sec = ticks % 60;                      /* split out seconds */
*    ticks /= 60;
 ldx   6,s point to utime
 ldd   2,x copy to local storage
 pshs  d
 ldd   ,x
 pshs  d
 leax  ,s point to our copy
 ldd   #60
 bsr   div32
 std   ,u seconds
*
*    tmp->tm_min = ticks % 60;                      /* split out minutes */
*    ticks /= 60;
 ldd   #60
 bsr   div32
 std   2,u minutes
*
*    tmp->tm_hr = ticks %24;                          /* split out hours */
*    days = ticks / 24;
 ldd   #24
 bsr   div32
 std   4,u hours
 ldd   2,x get days total
 std   4,s save days for later
*
*    for (tmp->tm_yr = 70; days >= 0; ++tmp->tm_yr)
*       days -= (fac = ((tmp->tm_yr & 3) ? 365 : 366));
*    tmp->tm_yr -= 1;
*    tmp->tm_yday = (days += fac);               /* adjust for overshoot */
 ldd   #70
 std   10,u iniz the year
lt1 leax  yrsiz,pcr
 ldb   11,u get current year
 andb  #3
 bne   lt2
 leax  2,x use leap size
lt2 ldd   4,s get saved days
 subd  ,x one year worth of days
 inc   11,u bump year
 std   4,s save remainder
 bcc   lt1
 addd  ,x fix up days left
 std   4,s
 dec   11,u unbump year
 std   14,u day of year
*
*    monsiz[2] = (tmp->tm_yr & 3) ? 28 : 29;
 ldb   11,u
 leax  monsiz,y
 lda   #29 assume leap year
 andb  #3
 beq   lt3
 lda   #28
lt3 sta   3,x

*    for (tmp->tm_mon = 1; days >= monsiz[tmp->tm_mon]; ++tmp->tm_mon)
*       days -= monsiz[tmp->tm_mon];
 clra
 clrb
 * ldd #$00ff month -1 for pre-incr
 std   8,u
 ldd   4,s
lt4 inc   9,u
 subd  ,x++
 bcc   lt4
 addd  -2,x
 addd  #1
 std   6,u

*    tmp->tm_wday = (days + 4) % 7;           /* extract the day of week */
 leax  ,s point to utime again
 ldd   2,x
 addd  #4
 std   2,x
 ldd   #7
 bsr   div32
 std   12,u day of week
*
*    return (tmp);
 tfr   u,d
 leas  6,s
 stu 4,s
 puls  u,pc
* }

div32
 clr   ,-s set up remainder
 clr   ,-s and clear carry
 pshs  d dave dsor
 ldb   #33 loop count
 pshs  b
 bra   div32b
div32a ldd   3,s
 subd  1,s subtract dsor
 bcs   div32b underflow
 std   3,s update remainder
div32b rol   3,x shoft ddend
 rol   2,x
 rol   1,x
 rol   ,x
 rol   4,s shift remainder
 rol   3,s
 dec   ,s count off
 bne   div32a
 com   3,x fix up dsor
 com   2,x
 com   1,x
 com   ,x
 lsr   3,s fix up remainder
 ror   4,s
 leas  3,s clean off counter and dsor
 puls  d,pc get remainder and return

*
*
* char   *
* asctime(tmp)
* struct tm *tmp;
*    {
*    sprintf(xx, "%s %s %2d %02d:%02d:%02d %04d\n",
*       days[tmp->tm_wday], months[tmp->tm_mon - 1], tmp->tm_day,
*       tmp->tm_hr, tmp->tm_min, tmp->tm_sec, tmp->tm_yr+1900);
*    return (xx);
*    }

_asctime pshs  u
 ldu   4,s
 ldd   10,u tm_yr
 addd  #1900
 pshs  d
 ldd   ,u tm_sec
 pshs  d
 ldd   2,u tm_min
 pshs  d
 ldd   4,u tm_hr
 pshs  d
 ldd   6,u tm_day
 pshs  d
 ldd   8,u tm_mon
* subd #1 fix the basing *+crk+ this needed fixed too
 subd  #1
 lslb
 rola
 lslb
 rola
 leax  >months,pcr
 leax  d,x
 pshs  x  month string
 ldd   12,u tm_wday
 lslb
 rola
 lslb
 rola
 leax  >days,pcr
 leax  d,x
 pshs  x day of week string
 leax  >datefmt,pcr
 pshs  x sprintf string spec
 leax  _datebuf,y
 pshs  x  dest buffer
 lbsr  _sprintf
 leas  18,s
 leax  _datebuf,y
 tfr   x,d
 puls  u,pc

*
*
* char  *
* ctime(ticks)
* long   *ticks;
*    {
*    struct tm *tmp;
*
*    return (asctime(localtime(ticks)));
*    }

_ctime
 ldd   2,s
 pshs  d
 lbsr  _localtime
 std   ,s
 lbsr  _asctime
 puls  x,pc

 endsect

 section rodata

yrsiz
 fdb 365,366

days
 fcc /Sun/
 fcb $00
 fcc /Mon/
 fcb $00
 fcc /Tue/
 fcb $00
 fcc /Wed/
 fcb $00
 fcc /Thu/
 fcb $00
 fcc /Fri/
 fcb $00
 fcc /Sat/
 fcb $00
months
 fcc /Jan/
 fcb $00
 fcc /Feb/
 fcb $00
 fcc /Mar/
 fcb $00
 fcc /Apr/
 fcb $00
 fcc /May/
 fcb $00
 fcc /Jun/
 fcb $00
 fcc /Jul/
 fcb $00
 fcc /Aug/
 fcb $00
 fcc /Sep/
 fcb $00
 fcc /Oct/
 fcb $00
 fcc /Nov/
 fcb $00
 fcc /Dec/
 fcb $00

datefmt
 fcc /%s %s %2d %02d:%02d:%02d %04d/
 fcb $00

 endsect

