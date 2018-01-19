/*
 * io.h - OS-9 I/O related calls
 */

#include "os.h"

typedef int path_id;

/* file access modes */
#define	FAM_READ	(1<<0)	// read
#define	FAM_WRITE	(1<<1)	// write
#define	FAM_UPDATE	(FAM_READ|FAM_WRITE)	// read + write

/* file access permissions */
#define	FAP_READ	(1<<0)	// read
#define	FAP_WRITE	(1<<1)	// write
#define	FAP_EXEC	(1<<2)	// execute
#define	FAP_PREAD	(1<<3)	// public read
#define	FAP_PWRITE	(1<<4)	// public write
#define	FAP_PEXEC	(1<<5)	// public execute
#define	FAP_SHARE	(1<<6)	// sharable
#define	FAP_DIR		(1<<7)	// directory

error_code _os_create(char *pathname, int mode, path_id *path, int perm);

error_code _os_open(char *pathname, int mode, path_id *path);
error_code _os_close(int mode);

error_code _os_read(path_id path, void *data, int *count);
error_code _os_readln(path_id path, void *data, int *count);

error_code _os_write(path_id path, void *data, int *count);
error_code _os_writeln(path_id path, void *data, int *count);

error_code _os_delete(char *pathname, int mode);
error_code _os_makdir(char *pathname, int perm);

error_code _os_seek(path_id path, long position);

error_code _os_ss_attr(char *pathname, int perm);

int getstat(int code, int param);
int setstat(int code, int param);