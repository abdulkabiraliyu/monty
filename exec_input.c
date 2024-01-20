#include "monty.h"

/**
 * execute_instructions - Read and execute instructions line by line
 *
 * @file: input file
 */
void execute_instructions(FILE *file)
{
	stack_t *stack = NULL;
	char line[1024];
	unsigned int line_number = 0;
	char *opcode;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		/** Tokenize the line to get opcode and argument */
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		/** Skip empty lines and comments */
		if (opcode == NULL || opcode[0] == '#')
			continue;

		/** Call a function to execute the opcode */
		exec_opcode(&stack, opcode, line_number);
	}

	free_stack(&stack);
}

/**
 * exec_opcode - execute the opcode commads
 *
 * @st: stack
 * @opcode: opcode commands
 * @line_num: line number
 */
void exec_opcode(stack_t **st, char *opcode, unsigned int line_num)
{
	/** Skip lines starting with # */
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"add", op_add},
		{"swap", op_swap},
		{"nop", op_nop},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},

		{NULL, NULL} /** End marker for the array */
	};

	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(st, line_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown opcode %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}

