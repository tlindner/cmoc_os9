#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

void test_create_and_delete_file()
{
	char *file = "existentfile";
	char buf[256];

    unlink(file);

	/* open file for reading and writing, with owner read/write permissions */
	int mode = FAM_READ | FAM_WRITE;
	int perms = FAP_READ | FAP_WRITE;
	int path = create(file, mode, perms);
	if (path != -1)
	{
		printf("%s [PASS] create(\"%s\", %d, %x) = %d\n", __func__, file, mode, perms, path);
		int result = close(path);
		if (result != -1)
		{
			printf("%s [PASS] close(%d) = %d\n", __func__, path, result);
			result = unlink(file);
			if (result != -1)
			{
				printf("%s [PASS] unlink(\"%s\") = %d\n", __func__, file, result);
			}
			else
			{
				printf("%s [FAIL] unlink(\"%s\") = %d, errno = %d\n", __func__, file, result, errno);
			}
		}
		else
		{
			printf("%s [FAIL] close(%d) = %d, errno = %d\n", __func__, path, result, errno);
		}
	}
	else
	{
		printf("%s [FAIL] create(\"%s\", %d, %x) = %d, errno = %d\n", __func__, file, mode, perms, path, errno);
	}
}

void test_open_nonexistent_file()
{
	char *file = "nonexistentfile";

	int mode = FAM_READ;
	int path = open(file, mode);
	if (path == -1)
	{
		printf("%s [PASS] open(\"%s\", %x) = %d\n", __func__, file, mode, path);
	}
	else
	{
		printf("%s [FAIL] open(\"%s\", %x) = %d\n", __func__, file, mode, path);
	}
}

void test_delete_nonexistent_file()
{
	char *file = "deletenonexistentfile";
	
	int result = unlink(file);
	if (result == -1)
	{
		printf("%s [PASS] unlink(\"%s\") = %d\n", __func__, file, result);
	}
	else
	{
		printf("%s [FAIL] unlink(\"%s\") = %d\n", __func__, file, result);
	}
}

/* test creation of a small file and seeking from various directions (start, current, end)
   coverage of this test is currently weak. A good test would be to add a large content file
   and seek within that.
   */
void test_create_and_seek()
{
	char *file = "text.txt";

	// delete the file if it exists, we don't care if we error here
	unlink(file);

	/* open file for reading and writing, with owner read/write permissions */
	int mode = FAM_READ | FAM_WRITE;
	int perms = FAP_READ | FAP_WRITE;
	int path = create(file, mode, perms);
	if (path != -1)
	{
		printf("%s [PASS] create(\"%s\", %x, %d) = %d\n", __func__, file, mode, perms, path);
		char *message = "this is a line of text\n";
		int length = strlen(message);
		int result = writeln(path, message, length);
		if (length == strlen(message))
		{
			printf("%s [PASS] writeln(%d, \"%s\", %d) = %d\n", __func__, path, message, length, result);
			long offset = 5;
			int whence = 0;
			long result = lseek(path, offset, whence);
#if 0
			if (result == offset)
			{
				// file position is now at 5
				char buf[32];
				int readsize = 2;
				
				printf("%s [PASS] lseek(%d, %l, %d) = %ld\n", __func__, path, offset, whence, result);
				int result = read(path, buf, readsize);
				if (2 == result && buf[0] == 'i' && buf[1] == 's')
				{
					// file position is now at 5 + 2 = 7
					printf("%s [PASS] read(%d, \"is\", %d) = %d\n", __func__, path, readsize, result);
				}
				else
				{
					printf("%s [FAIL] read(%d, \"is\", %d) = %d\n", __func__, path, readsize, result);
				}
			}
			else
			{
				printf("%s [FAIL] lseek(%d, %l, %d) = %ld\n", __func__, path, offset, whence, result);
			}
#endif
			close(path);
			unlink(file);
		}
		else
		{
			printf("%s [FAIL] writeln(%d, \"%s\", %d) = %d\n", __func__, path, message, length, result);
		}
	}
	else
	{
		printf("%s [FAIL] create(\"%s\", %x, %d) = %d\n", __func__, file, mode, perms, path);
	}
}

void test_make_directory()
{
	char *file = "newdirectory";

	int perm = FAP_READ | FAP_WRITE | FAP_PREAD;
	int result = mknod(file, perm);
	if (result == 0)
	{
		printf("%s [PASS] mknod(\"%s\", %d) = %d\n", __func__, file, perm, result);
	}
	else
	{
		printf("%s [FAIL] mknod(\"%s\", %d) = %d\n", __func__, file, perm, result);
	}
}

void test_make_and_attr_file()
{
	char *file = "newfile";

	int mode = FAM_READ | FAM_WRITE;
	int perm = FAP_READ | FAP_WRITE;
	int path = create(file, mode, perm);
	if (path != -1)
	{
		printf("%s [PASS] create(\"%s\", %x, %d) = %d\n", __func__, file, mode, perm, path);
		close(path);
#if 0
		perm = FAP_READ | FAP_WRITE | FAP_PREAD | FAP_PWRITE;
		int result = _os_ss_attr(file, perm);
		if (result == 0)
		{
		printf("%s [PASS] _os_ss_attr(\"%s\", %x, %d) = %d\n", __func__, file, mode, perm, path);
		}
		else
		{
			printf("%s [FAIL] _os_ss_attr(\"%s\", %d) = %d\n", __func__, file, perm, result);
		}
#endif
		unlink(file);
	}
	else
	{
		printf("%s [FAIL] create(\"%s\", %x, %d) = %d\n", __func__, file, mode, perm, path);
	}
}

int main()
{
	test_create_and_delete_file();
	test_open_nonexistent_file();
	test_delete_nonexistent_file();
	test_create_and_seek();
	test_make_directory();
	test_make_and_attr_file();

	return 0;
}
