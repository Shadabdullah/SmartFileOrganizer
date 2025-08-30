#include "../../../include/modules/utilities/copy.h"

#include "../../../include/errors.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

int copy(const char *destination_file, const char *source_file)
{

	FILE *source = fopen(source_file, "rb");

	if(source != NULL)
	{

		FILE *destination = fopen(destination_file, "wb");

		if(destination != NULL)
		{
			int read_bytes, write_bytes;
			
			char buffer[COPY_BUFFER_SIZE];

			while((read_bytes = fread(buffer, sizeof(char), COPY_BUFFER_SIZE, source)) > 0)
			{
				write_bytes = fwrite(buffer, sizeof(char), read_bytes, destination);

				if(write_bytes != read_bytes)
				{
					fprintf(stderr, "Error on copying: Read/Write mismatch!\n");
					break;
				}
			}
	
			long source_eof, destination_eof;

			fseek(source, 0, SEEK_END);
			fseek(destination, 0, SEEK_END);
	
			source_eof = ftell(source);
			destination_eof = ftell(destination);
	
			if(source_eof == destination_eof)
				fprintf(stdout, "Successful copy! ( filename: \x1b[31m%s\x1b[0m )\n", destination_file);
			else
			{	
				fprintf(stderr, "Error on copy: Mismatch of EOF's source/destination!\n");
				return FAIL_NO_COPY;
			}
			
			if(fclose(destination) == 0)
			{
				//fprintf(stdout, "Closed writing file!\n");
			}
			else
			{
				fprintf(stderr, "Error on closing writing file: (%s)\n", strerror(errno));
				return FAIL_CLOSE_FILE;
			}

		}
		else
		{
			fprintf(stderr, "Error on opening file for writing: (%s)\n", strerror(errno));
			return FAIL_OPEN_FILE;
		}

		if(fclose(source) == 0)
		{
			//fprintf(stdout, "Closed file for reading!\n");
		}
		else
		{
			fprintf(stderr, "Error on closing reading file: (%s)\n", strerror(errno));
			return FAIL_CLOSE_FILE;
		}

	}
	else
	{
		fprintf(stderr, "Error on opening file for reading: (%s)\n", strerror(errno));
		return FAIL_OPEN_FILE;
	}

	return 0;
}

