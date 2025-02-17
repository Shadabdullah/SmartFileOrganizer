#include <stdio.h>

#include "../include/file_ops.h"

int main(int argc, char **argv)
{
  printf("Smart File Manager CLI\n");

  if (argc > 1)
  {
    printf("arg[%d]: %s\n", 1, argv[1]);

    const char *file_extension = handle_file_extension(argv[1]);
    printf("File extension: %s\n", file_extension);
  }
  return 0;
}
