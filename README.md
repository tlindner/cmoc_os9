# CMOC C Library support for OS-9/NitrOS-9

CMOC is an excellent ANSI C cross-compiler by Pierre Sarrazin. It supports the creation of OS-9 exectuables, which needs a complete C library. [Download CMOC here](https://perso.b2b2c.ca/~sarrazip/dev/cmoc.html).

This project aims to deliver two libraries: the standard C library (libc.a) and the CGFX library (libcgfx.a).

The code for the standard C library is based off of the Kreider C library, with yet-to-be ported files under the lib/todo folder.

Likewise, the code for the CGFX library is based off of Mike Sweet's CGFX7 library, with yet-to-be ported files under the cgfx/todo folder.

## Building

You will need LWTOOLS and ToolShed to build this library.

To make the libc.a C library, type:

```
cd cmoc_os9
cd lib; make
cd ../cgfx; make
```

From there, you can build the unit tests:
```
cd ../unittest
make clean dsk
```

This will create a disk image called 'test.dsk' which you can mount in an emulator and run under NitrOS-9. A convenient script named 'go' is placed in the root folder of the disk. You can run this script to run all of the unit tests.

## Differences from the original Microware C Library

The original Microware C library worked within the limitations of the Microware K&R C compiler (e.g. the first 8 characters of a variable or function name were significant.) CMOC eliminates many of those limitations since it's a cross-compiler that runs on modern platforms.

Because of this, we have more freedom to be verbose with function names that were horribly abbreviated, and use calling conventions that are more uniform across the library.

An example of this are the low level C functions for opening and manipulating files in OS-9. Here's the way you would do this in Microware's K&R C compiler:

```
	int p = open("file", S_IREAD | S_IWRITE); // open file for reading and writing
	if (p != -1) {
		// success - valid path
		char buf[10];
		
		int c = read(p, buf, 10);
		if (c == -1) {
			// failure - print the error
			printf("error reading: %d\n", errno);
		}
	} else {
		// failure - print the error
		printf("error opening: %d\n", errno);
	}
```

While this code works and is certainly readable, it tends to fall in the trap of using the return value for one thing or another, complicating error handling.

In the case of open(), the return value is a path... unless -1 is returned, indicated an error occurred.

In the case of read(), a return value is the number of bytes read... unless -1 is returned, indicating an error occurred.

In both cases, we end up having to fetch the error in the global errno variable.

Microware moved to a more uniform method of function usage in [their Ultra C compiler](http://rab.ict.pwr.wroc.pl/dydaktyka/supwa/os9/MWARE/pdf/ultrac_lib_ref.pdf), which reserved the return value strictly for the error code. Here's the same code above rewritten with this new paradigm:

```
	pathid p;
	error_code result = _os_open("file", FAM_READ | FAM_WRITE, &p); // open file for reading and writing
	if (result == 0) {
		// success - valid path
		char buf[10];
		
		int size = 10;
		result = _os_read(p, buf, &size);
		if (result != 0) {
			// failure - print the error
			printf("error reading: %d\n", result);
		}
	} else {
		// failure - print the error
		printf("error opening: %d\n", result);
	}
```

There are several differences in this code:

1. The functions are prepended with '_os_'
2. The return value for the functions are reserved for the error -- no needing to pull the error out of errno.
3. The sane values that were being returned in the result of the function are now passed by reference.

This is arguably a cleaner, more consistent approach to using the low-level I/O and other system calls, and is the path being pursued in the creation of this library.

## Work to be done

Under the lib/todo folder are .as files which need to be brought into the CMOC format. Also, additional unit tests need to be written.
