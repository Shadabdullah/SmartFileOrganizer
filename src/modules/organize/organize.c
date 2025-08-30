#include "../../../include/modules/organize/organize.h"

//Sorters
#include "../../../include/modules/organize/sorters/default.h"
#include "../../../include/modules/organize/sorters/images/sorter.h"
#include "../../../include/modules/organize/sorters/videos/sorter.h"
#include "../../../include/modules/organize/sorters/others/sorter.h"



#include <stdio.h>
#include <string.h>
#include <errno.h>

#define OPTION_NAME_SIZE 16
#define FORMAT_LENGTH 32

int organize(sfo_state *state)
{
	
	options_list();

	char option_name[OPTION_NAME_SIZE];

	if(fgets(option_name, sizeof(option_name), stdin) != NULL)
	{
		option_name[strcspn(option_name, "\n")] = 0;

		switch(option_name[0])
		{
			case '1':
			case 'd':
			case 'D':
				{
					
					default_sorter("/default");

				}
				break;
			case '2':
			case 'i':
			case 'I':
				{
					
					images_sorter("/images");
				
				}
				break;
			case '3':
			case 'v':
			case 'V':
				{

					videos_sorter("/videos");

				}
				break;
			case '4':
			case 'o':
			case 'O':
				{

					others_sorter("/others");

				}
				break;

		}

	}
	else
	{
		fprintf(stderr, "Error on selecting option: (%s)\n", strerror(errno));
	}

	//Output


}

void options_list()
{

	char format[FORMAT_LENGTH];
	strcpy(format, "%-25s%-25s%-45s\n");


	fprintf(stdout, "\n Options for organizing your directories: \n\n");

	fprintf(stdout, format, "Option number", "Option name", "Description");
	
	fprintf(stdout, "\n");

	fprintf(stdout, format, "[ 1 ]", "( default / d )", "Default option for creating directory and soft link to it.");
	fprintf(stdout, format, "[ 2 ]", "( images  / i )", "Creates images directory and soft link to it.");
	fprintf(stdout, format, "[ 3 ]", "( videos  / v )", "Creates videos directory and soft link to it.");
	fprintf(stdout, format, "[ 4 ]", "( others  / o )", "Creates others directory and soft link to it.");

	fprintf(stdout, "\n\n");

	//ToDo color set for different options/commands/etc

	fprintf(stdout, "[ sfo ]\x1b[34m[ organize ]\x1b[0m: ");
}
