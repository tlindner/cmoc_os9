#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <io.h>

void test_putc()
{
	assert(putc('1', stdout) == '1');
//	assert(putc('\n', stdout) == '\n');

	path_id p;
	_os_create("file", FAM_WRITE, &p, FAP_READ | FAP_WRITE);
	int size = 13;
	_os_write(p, stdout, &size);
	_os_close(p);

	assert(putc('1', stdout) == '1');
	assert(putc('\n', stdout) == '\n');
	assert(putc('2', stderr) == '2');
}

void test_putw()
{
	assert(putw(0x3334, stdout) == 0x3334);
	assert(putw(0x410D, stdout) == 0x410D);
}

void test_printf()
{
	fprintf(stderr, "Hello world!\n");
	fprintf(stderr, "Hello %s world!\n", "small");
	fprintf(stderr, "Hello %s %s!\n", "CoCo", "community");
}

int main()
{
	test_putc();
//	test_putw();
	test_printf();

	return 0;
}
