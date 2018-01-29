#ifndef _STRING_H
#define _STRING_H

char  *strcat(char *s1, char *s2);
char  *strncat(char *s1, char *s2, size_t n);
char  *strhcpy(char *dst, char *src);
char  *strcpy(char *dst, char *src);
char  *strncpy(char *dst, char *src, size_t len);
char  *strclr();
char  *strucat();
char  *strucpy();
char  *index();
char  *rindex();
char  *reverse();
char  *strend();
int   strcmp(char *s1, char *s2);
int   strncmp(char *s1, char *s2);
int   strlen(char *s);
int   strucmp();
int   strnucmp();
int   patmatch();
char  *strchr(char *s, int c);
char  *strrchr(char *s, int c);
char  *strspn();
char  *strcspn();
char  *strtok(char *str, char *step);
char  *strpbrk();


void *memcpy(void *dst, void *src, size_t len);
void *memset(void *dst, int c, size_t len);
void *memchr(void *data, int c, size_t len);

#endif