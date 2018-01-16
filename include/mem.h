/*
 * mem.h - memory functions
 */

#include "os.h"

/*
// these are supplied by CMOC and are commented out for now
void *memcpy(void *dst, char *src, int len);
void *memset(void *dst, char c, int len);
*/
void *memchr(void *data, int c, size_t len);
