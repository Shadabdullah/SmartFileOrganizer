#define sfo_abort(MSG) (fprintf(stderr,MSG))

/**
 * Error messages
 */

#define MSG_FAIL_INIT_MAGIC "Fail to initialize magic library"
#define MSG_FAIL_MAGIC_ERROR "Magic error"
#define MSG_FAIL_MAGIC_LOAD "Fail to load magic database"
#define MSG_FAIL_OPEN_FILE "Error opening file"
#define MSG_FAIL_MAGIC_DESCRIPTOR "Could not read file with magic descriptor function"
#define MSG_FAIL_GET_MIME_TYPE "Fail to get file MIME type"

#define MSG_FAIL_FILE_BYTES_READ "Fail to read all the bytes from the file"
#define MSG_FAIL_FILE_INFO_DETAILS "Failed to identify file type & description"
#define MSG_FAIL_NO_EXTENSION "There is no extension, probably binary file"

#define MSG_FAIL_NO_CWD "Cannot get the current working directory"
#define MSG_FAIL_NO_SPACE "Cannot allocate enough space"

#define MSG_FAIL_COPY_CWD "Failed to copy the current working directory"

#define MSG_FAIL_CREATE_DIRECTORY "Failed to create a new directory"
#define MSG_FAIL_CREATE_SYMBOLIC_LINK "Failed to create symbolic link"

#define MSG_FAIL_CREATE_BACKUP "Failed to backup the files in the directory"

#define MSG_FAIL_CREATE_ARCHIVE_STRUCT "Failed to create archive struct for the specified file"
#define MSG_FAIL_SUPPORT_ARCHIVE_FILTERS "Failed to support archive filters for the specified file"
#define MSG_SUPPORT_ARCHIVE_FORMATS "Failed to support archive formats for the specified file"
#define MSG_FAIL_OPEN_ARCHIVE_FILE "Failed to open the specified archive file"

#define MSG_FAIL_MEMORY_ALLOC "Memory allocation failed"

/**
 * Error codes
 */

#define FAIL_FILE_NOT_FOUND 4041
#define FAIL_INIT_MAGIC 4042
#define FAIL_LOAD_MAGIC_DATABASE 4043
#define FAIL_GET_MIME_TYPE 4044
#define FAIL_MAGIC_DESCRIPTOR 4045

#define FAIL_BYTES_READ 1011
#define FAIL_OPEN_FILE 1012
#define FAIL_FILE_INFO_DETAILS 1013
#define FAIL_OPEN_DIRECTORY 1014
#define FAIL_CLOSE_FILE 1015

#define FAIL_NO_EXTENSION 2011

#define FAIL_NO_CWD 3001
#define FAIL_NO_COPY 3002
#define FAIL_CREATE_NEW_DIRECTORY 3003
#define FAIL_CREATE_SYMBOLIC_LINK 3004 
#define FAIL_OPEN_DIRECTORY_STREAM 3005
#define FAIL_CREATE_DUPLICATE_NAME 3006
#define FAIL_NO_FILES_TO_MOVE 3007


#define FAIL_CREATE_ARCHIVE_STRUCT 5001
#define FAIL_SUPPORT_ARCHIVE_FILTERS 5002
#define FAIL_SUPPORT_ARCHIVE_FORMATS 5003
#define FAIL_OPEN_ARCHIVE_FILE 5004
