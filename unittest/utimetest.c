#include <stdio.h>
// #include <time.h>
#include <utime.h>
#include <debug.h>
#include <fcntl.h>
// typedef unsigned int size_t;
#include <sys/types.h>
#include <string.h>

#define I$ReadLn            0x8B

struct _os_time p = {2014 - 1900, 3, 4, 11, 33, 22};
#define P_SECS_EPOCH 1393932802L
char *pStr = "Tue Mar  4 11:33:22 2014";
struct _os_time epoch = {1970 - 1900, 1, 1, 0, 0, 0};
char *epochStr = "Thu Jan  1 00:00:00 1970";
#define EPOCH_START 0L


void test_o2utime()
{
	long t = o2utime(&epoch);
	if (t == EPOCH_START) {
		printf("%s [PASS] o2utime(): epoch\n", __func__);
	}
	else
	{
		printf("%s [FAIL] o2utime(): epoch: expected %ld but got %ld\n", __func__, EPOCH_START, t);
		LPX(t);
	}	

	t = o2utime(&p);
	if (t == P_SECS_EPOCH) {
		printf("%s [PASS] o2utime(): date\n", __func__);
	}
	else
	{
		printf("%s [FAIL] o2utime(): date: expected %ld but got %ld\n", __func__, P_SECS_EPOCH, t);
		LPX(t);
	}
}


void test_time()
{
	_os_setime(&p);
	long t = time(0);
	if (t == P_SECS_EPOCH) {
		printf("%s [PASS] time() by value\n", __func__);
	}
	else
	{
		printf("%s [FAIL] time() by value: expected %ld but got %ld\n", __func__, P_SECS_EPOCH, t);
		LPX(t);
	}
	_os_setime(&p);
	time(&t);
	if (t == P_SECS_EPOCH) {
		printf("%s [PASS] time() by ptr\n", __func__);
	}
	else
	{
		printf("%s [FAIL] time() by ptr: expected %ld but got %ld\n", __func__, P_SECS_EPOCH, t);
		LPX(t);
	}
}

void test_ctime()
{
	long t = P_SECS_EPOCH;
	char *ds = ctime(&t);
	// BREAK;
	if (strcmp(pStr, ds) == 0)
	{
		printf("%s [PASS] ctime() date\n", __func__);
	}
	else
	{
		printf("%s [FAIL] ctime() date\n", __func__);
		printf("%s pStr (%s)\n", __func__, pStr);
		printf("%s   ds (%s)\n", __func__, ds);
	}

}

int main()
{
	pflinit();
	test_o2utime();
	test_time();
	test_ctime();

	return 0;
}
