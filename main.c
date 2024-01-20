#include "monty.h"

char *arg = NULL;
int current_mode = 0;

/**
 * main - Monty Interpreter: entry point
 *
 * @argc: no of argument passed
 * @argv: pointer to string pointer
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *file_path;

	/** Check the number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/**Get the file path from the command line argument */
	file_path = argv[1];

	/** Call a function to handle the file processing */
	process_file(file_path);

	return (0);
}

