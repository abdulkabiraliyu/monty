#include "monty.h"

/**
 * op_push - Function to handle the "push" opcode
 *
 * @stack: stack
 * @line_number: line numebr
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;

	/** Check if argument is provided */
	if (arg == NULL || !is_valid_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Convert the argument to an integer using atoi */
	value = atoi(arg);

	/** Create a new stack node and push it onto the stack */
	new_node = my_malloc(sizeof(stack_t));

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * op_pall - Function to handle the "pall" opcode
 *
 * @stack: stack
 * @line_number: line numebr
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	/** Print all values on the stack */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * is_valid_integer - check for valid integer
 *
 * @str: input number
 *
 * Return: integer
 */
int is_valid_integer(const char *str)
{
	int i;
	/** Check if the string contains only digits */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		{
			return (0); /** Not a valid integer */
		}
	}
	return (1);
}

