#include "monty.h"
/**
 * process_file - read the instructions in the monty byte code
 *
 * @file_path: file path
 */

void process_file(char *file_path)
{
	/** Open the file*/
	FILE *file = fopen(file_path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	/** Call a function to read and execute instructions */
	execute_instructions(file);

	/** Close the file */
	fclose(file);
}

