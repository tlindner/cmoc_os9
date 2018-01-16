#include <os.h>

void test_writeln_syscall()
{
	char *message = "print this!\n";
	registers_6809 regs;
	
	regs.a = 1;         // standard output
	regs.x = message;
	regs.y = strlen(message);

	/* open file for reading and writing, with owner read/write permissions */
	int syscall = I$WritLn;
	error_code result = _os_syscall(syscall, &regs);
	if (result == 0)
	{
		printf("%s [PASS] _os_syscall(%d, [%d]) = %d\n", __func__, syscall, 0, result);
	}
	else
	{
		printf("%s [FAIL] _os_syscall(%d, [%d]) = %d\n", __func__, syscall, 0, result);
	}
}

int main()
{
	test_writeln_syscall();

	return 0;
}
