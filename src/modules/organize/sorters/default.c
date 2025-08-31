#include "modules/organize/sorters/default.h"

int default_sorter(char *name)
{

	struct dirent *entries;
	DIR *dir_name;

	char cwd_buffer[PATH_MAX];

	if(getcwd(cwd_buffer, PATH_MAX) != NULL)
	{

		dir_name = opendir(cwd_buffer);

		if(dir_name)
		{

			//Check if there is any files to move

			int files_counter = 0;

			while((entries = readdir(dir_name)) != NULL)
			{
				if(strcmp(entries->d_name, "..") == 0 || strcmp(entries->d_name, ".") == 0 || strcmp(entries->d_name, "sfo") == 0)
					continue;
				
				switch(entries->d_type)
				{
					case DT_REG:
						{
							files_counter++;
						}
						break;
				}
			}

			//Reset directory stream
			rewinddir(dir_name);
		
			if(files_counter > 0)
			{
				char new_directory[strlen(cwd_buffer) + strlen(name) + 1];

				strcpy(new_directory, cwd_buffer);
		
				if(strcat(new_directory, name) != NULL)
				{
					fprintf(stdout, "\nDirectory: \x1b[34m%s\x1b[0m\n", new_directory);
				
					if(mkdir(new_directory, 0755) == 0)
					{
	
						fprintf(stdout, "\nSuccess on creating \x1b[33m%s\x1b[0m directory!\n\n", name);
					}
					else
					{
						fprintf(stderr, "Error on creating directory: (%s)\n", strerror(errno));
						return FAIL_CREATE_NEW_DIRECTORY;
					}
				}
				else
				{
					fprintf(stderr, "Error on concat default with cwd!\n");
				}

				
				while((entries = readdir(dir_name)) != NULL)
				{
					if(strcmp(entries->d_name, "..") == 0 || strcmp(entries->d_name, ".") == 0 || strcmp(entries->d_name, "sfo") == 0)
						continue;
				
					switch(entries->d_type)
					{
						case DT_REG:
						{
							
							char new_dirname[strlen(new_directory) + strlen(entries->d_name) + 1];
							

							if(strcpy(new_dirname, new_directory) != NULL)
							{

								if(strcat(new_dirname, "/") != NULL)
								{
									
								
									if(strcat(new_dirname, entries->d_name) != NULL)
									{

										//Moving the files
										if(rename(entries->d_name, new_dirname) == 0)
										{
											
											char moved[strlen(name) + strlen(entries->d_name) + 2];


											if(strcpy(moved, name) != NULL)
											{
												if(strcat(moved, "/") != NULL)
												{
													if(strcat(moved, entries->d_name) != NULL)
													{
														fprintf(stdout, "Moved: ( \x1b[34m%s\x1b[0m ) \n", moved);
													}
												}
											}
										}
										else
										{
											fprintf(stderr, "Error on rename: ( %s )\n", strerror(errno));
										}
									}
									else
									{
										fprintf(stderr, "Error on creating duplicate name: (%s)\n", strerror(errno));
										return FAIL_CREATE_DUPLICATE_NAME;
									}

								}
								else
								{
									fprintf(stderr, "Error on concat strings!\n");
								}
								
							}
							else
							{
								fprintf(stderr, "Error on copying strings!\n");
							}
						}
						break;
					}
				}

				//Creating symbolic/soft link to default directory				

				char symlink_name[strlen(name) + 4 ]; // .sfo\0 without slash at the beginning

				memmove(symlink_name, name + 1, strlen(name) + 1); // move memory area to symlink_name without first byte of name, the slash

				strcat(symlink_name, ".sfo");

				fprintf(stdout, "Symlink name: %s\n", symlink_name);
	
				if(symlink(new_directory, symlink_name) == 0)
				{
					fprintf(stdout, "\n Symbolic link was created to the %s directory! ( \x1b[31m%s\x1b[0m )\n", name, new_directory);
				}
	
				fprintf(stdout, "\nOrganize done!\n");
	
			}
			else
			{
				fprintf(stderr, "\nThere is no files to move!\n");
				return FAIL_NO_FILES_TO_MOVE;
			}
			//End check if there is any files to move

			
			if(closedir(dir_name) == 0)
			{
				//Closed directory stream
			}
			else
			{
				fprintf(stderr, "Error on closing directory stream: ( %s )\n", strerror(errno));
			}


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
