#include <stdio.h>
#include <assert.h>
#include <io.h>

void test_putc()
{
	assert(putc('1', stdout) == '1');
	assert(putc('2', stderr) == '2');
}

void test_putw()
{
	assert(putw(0x3334, stdout) == 0x3334);
	assert(putw(0x4142, stdout) == 0x4142);
}

void test_printf()
{
	printf("Hello world!\n");
	printf("Hello %s world!\n", "small");
	printf("Hello %s %s %s!\n", "CoCo", "community");
}

int main()
{
	test_putc();
	test_putw();
	test_printf();

	return 0;
}
