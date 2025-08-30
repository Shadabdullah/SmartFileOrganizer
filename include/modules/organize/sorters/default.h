#ifndef SORTER_DEFAULT_H
#define SORTER_DEFAULT_H

#include "../../../errors.h"

#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>

int default_sorter(char *name);

#endif
