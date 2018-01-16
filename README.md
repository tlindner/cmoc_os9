# CMOC C Library support for OS-9/NitrOS-9
CMOC is an excellent ANSI C cross-compiler by Pierre Sarrazin. It supports the creation of OS-9 exectuables, which needs a complete C library.

This is that C library.

The code for the library is based off of the Kreider C library.

## Building

You will need LWTOOLS and ToolShed to build this library.

To make the libc.a C library, type:

```
cd cmoc_os9
cd lib; make
```

From there, you can build the unit tests:
```
cd ../unittest
make clean dsk
```

This will create a disk image called 'test.dsk' which you can mount in an emulator and run under NitrOS-9. A convenient script named 'go' is placed in the root folder of the disk. You can run this script to run all of the unit tests.
