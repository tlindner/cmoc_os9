#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

void test_putc()
{
	assert(putc('1', stdout) == '1');
	assert(putc('2', stdout) == '2');
	assert(putc('3', stdout) == '3');
	assert(putc('\n', stdout) == '\n');
}

void test_putw()
{
	assert(putw(0x4344, stdout) == 0);
	assert(putw(0x4142, stdout) == 0);
	assert(putc('\n', stdout) == '\n');
	fflush(stdout);
}

void test_puts()
{
    puts( "puts test" );
}

void test_fputs(FILE *fp)
{
    fputs("fputs test", fp );
    fputs("\n", fp );
}

void test_printf()
{
	printf("printf Hello world!\n");
	printf("printf Hello %s world!\n", "small");
	printf("printf Hello %s %s!\n", "CoCo", "community");
	printf("printf Long value is %ld\n", 32L);
}

void test_fprintf(FILE *fp)
{
	fprintf(fp, "fprintf Hello world!\n");
	fprintf(fp, "fprintf Hello %s world!\n", "small");
	fprintf(fp, "fprintf Hello %s %s!\n", "CoCo", "community");
}

void test_fopen()
{
//	FILE *fp = fopen("x", "r");
//	fclose(fp);
}

int main()
{
	test_putc();
	test_putw();
	test_puts();
	test_fputs(stdout);
	test_printf();
	test_fprintf(stdout);
	test_fprintf(stderr);

	return 0;
}
