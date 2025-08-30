#ifndef BACKUP_COPY_H
#define BACKUP_COPY_H

#define COPY_BUFFER_SIZE 4096

/**
 *	Description: Copying two files by reading and writing in binary mode, where the *destination_file is the copied *source_file
 *
 ***/

int copy(const char *destination_file, const char *source_file);

#endif
