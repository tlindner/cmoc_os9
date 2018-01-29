#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <os.h>

void test_memcpy()
{
    char *src = "test";
    char dst[5];
    int count = 4;
    void *result = memcpy(dst, src, count);
    
    if (dst[0] == 't' && dst[1] == 'e' && dst[2] == 's' && dst[3] == 't')
    {
		printf("%s [PASS] memcpy(%X, %X, %d) = %X\n", __func__, dst, src, count, result);
    }
    else
    {
		printf("%s [FAIL] memcpy(%X, %X, %d) = %X\n", __func__, dst, src, count, result);
    }
}

void test_memset()
{
    char src = 'X';
    char dst[5];
    int count = 5;
    void *result = memset(dst, src, count);
    
    if (dst[0] == 'X' && dst[1] == 'X' && dst[2] == 'X' && dst[3] == 'X' && dst[4] == 'X')
    {
		printf("%s [PASS] memset(%X, %X, %d) = %X\n", __func__, dst, src, count, result);
    }
    else
    {
		printf("%s [FAIL] memset(%X, %X, %d) = %X\n", __func__, dst, src, count, result);
    }
}

void test_memchr()
{
    char *src = "ABCDEFGHIJKLMNOP";
    char locate = 'H';
    int count = strlen(src);
    void *result = memchr(src, locate, count);
    
    if (result == src + 7)
    {
		printf("%s [PASS] memchr(%X, %X, %d) = %X\n", __func__, src, locate, count, result);
    }
    else
    {
		printf("%s [FAIL] memchr(%X, %X, %d) = %X\n", __func__, src, locate, count, result);
    }

    // locate a character that is NOT in the source string
    locate = 'Z';
    result = memchr(src, locate, count);
    
    if (result == 0x0000)
    {
		printf("%s [PASS] memchr(%X, %X, %d) = %X\n", __func__, src, locate, count, result);
    }
    else
    {
		printf("%s [FAIL] memchr(%X, %X, %d) = %X\n", __func__, src, locate, count, result);
    }
}

void test_ibrk()
{
	void *result = ibrk(128);
}

int main(int argc, char **argv)
{
	test_ibrk();
	return 0;
	test_memcpy();
	test_memset();
	test_memchr();

	return 0;
}
