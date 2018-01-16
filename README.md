# CMOC C Library support for OS-9/NitrOS-9
CMOC is an excellent ANSI C cross-compiler by Pierre Sarrazin. It supports the creation of OS-9 exectuables, which needs a complete C library. [Download it here.](https://perso.b2b2c.ca/~sarrazip/dev/cmoc.html)

This is that C library.

The code for the library is based off of the Kreider C library, with yet-to-be ported files under the lib/todo folder.

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

## Work to be done

Under the lib/todo folder are .as files which need to be brought into the CMOC format. Also, additional unit tests need to be written.
