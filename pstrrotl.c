#include "monty.h"
#include <ctype.h>

/**
 * op_pstr - Function to handle the "pstr" opcode
 *
 * @stack: pointer to stack pointers
 * @line_number: line number
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	/** Print the string starting at the top of the stack */
	while (current != NULL && current->n != 0 && is_ascii(current->n))
	{
		putchar((char)current->n);
		current = current->next;
	}

	/** Print a new line*/
	putchar('\n');
}

/**
 * op_rotl - Function to handle the "rotl" opcode
 *
 * @stack: stack
 * @line_number: line numebr
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	/** Check if the stack is not empty and has at least two elements */
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;
		stack_t *second_last = *stack;

		/** Find the last and second last elements */
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}

		/** Rotate the stack*/
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
/**
 * is_ascii - check if a character is an ascii
 *
 * @c: in character
 *
 * Return: integer
*/
int is_ascii(int c)
{
	return (c >= 0 && c <= 127);
}

