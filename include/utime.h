#include <time.h>

#ifndef UTIME_H
#define UTIME_H

struct tm {
      int   tm_sec;           /* seconds (0 - 59) */
      int   tm_min;           /* minutes (0 - 59) */
      int   tm_hour;          /* hours (0 - 23) */
      int   tm_mday;          /* day of month (1 - 31) */
      int   tm_mon;           /* month of year (0 - 11) */
      int   tm_year;          /* year (year - 1900) */
      int   tm_wday;          /* day of week (Sunday = 0) */
      int   tm_yday;          /* day of year (0 - 365) */
      int   tm_isdst;         /* not used */
      };
long        time(long *);           /* just like Unix */
struct tm   *localtime(long *);     /* just like Unix */
char        *asctime(struct tm *);       /* just like Unix */
char        *ctime(long *);         /* just like Unix */
long        o2utime(struct os_time *);        /* converts os9 style buf to Unix long */
void        u2otime(char *, struct os_time *);        /* converts 'tm' to os9 char buf */

#endif
