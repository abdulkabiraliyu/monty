#include "monty.h"

/**
 * op_mod -Function to handle the "mod" opcode
 *
 * @stack: pointer to stack pointers
 * @line_number: line number
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	/** Check if the stack contains at least two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Check if the top element of the stack is not zero */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/**
	 * Compute the rest of the division of the
	 * second top element by the top element
	 */
	(*stack)->next->n %= (*stack)->n;

	/** Remove the top element */
	op_pop(stack, line_number);
}

/**
 * op_pchar - Function to handle the "pchar" opcode
 *
 * @stack: pointer to stack pointers
 * @line_number: line number
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	/** Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Get the ASCII value from the top of the stack*/
	ascii_value = (*stack)->n;

	/** Check if the ASCII value is within the valid range */
	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Print the character */
	putchar((char)ascii_value);
	putchar('\n');

	/**Pop the top element */
	op_pop(stack, line_number);
}

