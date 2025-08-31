#include "modules/backup/directories.h"
#include "modules/utilities/copy.h"

#include "errors.h"

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>

int cwd_all_files(char *pathname)
{

	struct dirent *entries;
	DIR *dir_name;

	char cwd_buffer[PATH_MAX];

	if(getcwd(cwd_buffer, PATH_MAX) != NULL)
	{

		dir_name = opendir(cwd_buffer);

		if(dir_name)
		{

			char backup_directory[strlen(cwd_buffer) + strlen("/backup/") + 1];

			strcpy(backup_directory, cwd_buffer);
		
			if(strcat(backup_directory, "/backup/") != NULL) // Default for now
			{
				fprintf(stdout, "\nDirectory: \x1b[34m%s\x1b[0m\n", backup_directory);
				
				if(mkdir(backup_directory, 0755) == 0)
				{

					fprintf(stdout, "\nSuccess on creating backup directory!\n\n");
				}
				else
				{
					fprintf(stderr, "Error on creating directory: (%s)\n", strerror(errno));
					return FAIL_CREATE_NEW_DIRECTORY;
				}
			}
			else
			{
				fprintf(stderr, "Error on concat backup directory!\n");
			}

			while((entries = readdir(dir_name)) != NULL)
			{
				if(strcmp(entries->d_name, "..") == 0 || strcmp(entries->d_name, ".") == 0)
					continue;
				
				switch(entries->d_type)
				{
					case DT_REG:
						{
							//Simple duplicate name
							char backup_dirname[strlen(entries->d_name) + strlen("backup/") + 1];

							//ToDo: Creating names for the backup files?
							strcpy(backup_dirname, "backup/");
							if(strcat(backup_dirname, entries->d_name) != NULL)
							{
								
								//Actual copy of the files
								copy(backup_dirname, entries->d_name);

							}
							else
							{
								fprintf(stderr, "Error on creating duplicate name: (%s)\n", strerror(errno));
								return FAIL_CREATE_DUPLICATE_NAME;
							}

						}
						break;
				}
			}

			fprintf(stdout, "\nBackup done!\n");
		}
		else
		{
			fprintf(stderr, "Error on opening directory stream!\n");
			return FAIL_OPEN_DIRECTORY_STREAM;
		}
		
	}
	else
	{
		fprintf(stderr, "Could not get the current working directory: (%s)\n", strerror(errno));
		return FAIL_NO_CWD;
	}


	return 0;
}
