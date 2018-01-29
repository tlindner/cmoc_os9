#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char eolchar = '\r';

void test_putc()
{
	assert(putc('1', stdout) == '1');
	assert(putc('2', stdout) == '2');
	assert(putc('3', stdout) == '3');
	assert(putc(eolchar, stdout) == eolchar);
}

void test_putw()
{
	assert(putw(0x4344, stdout) == 0);
	assert(putw(0x4142, stdout) == 0);
	fflush(stdout);
}

void test_printf()
{
	printf("printf Hello world!%c", eolchar);
	printf("printf Hello %s world!%c", "small", eolchar);
	printf("printf Hello %s %s!%c", "CoCo", "community", eolchar);
}

void test_fprintf(FILE *fp)
{
	fprintf(fp, "fprintf Hello world!%c", eolchar);
	fprintf(fp, "fprintf Hello %s world!%c", "small", eolchar);
	fprintf(fp, "fprintf Hello %s %s!%c", "CoCo", "community", eolchar);
}

int main()
{
	test_putc();
	test_putw();
	test_printf();
	test_fprintf(stdout);
	test_fprintf(stderr);

	return 0;
}
