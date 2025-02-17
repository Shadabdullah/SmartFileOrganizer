#include <string.h>

#include "../include/file_ops.h"

const char *handle_file_extension(const char *filename)
{
    char *file_extension = strrchr(filename, '.'); // Find last '.'
    if (!file_extension || file_extension == filename)
    {
        return NULL;
    }

    char *substr = file_extension + 1;                   // storing the characters after the dot ( using substr for removing the dot )
    memmove(file_extension, substr, strlen(substr) + 1); // moving the substr (source) to the file_extension(destination)

    return file_extension;
}