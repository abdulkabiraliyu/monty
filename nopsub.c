#include "monty.h"

/**
 * op_nop - Function to handle the "nop" opcode
 *
 * @stack: stack
 * @line_number: line number
 */
void op_nop(stack_t **stack, unsigned int line_number)
{

	/** This opcode does nothing */
	(void)stack;
	(void)line_number;
}

/**
 * op_sub - Function to handle the "sub" opcode
 *
 * @stack: stack
 * @line_number: line number
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	/** Check if the stack contains at least two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Subtract the top element from the second top element of the stack */
	(*stack)->next->n -= (*stack)->n;

	/** Remove the top element */
	op_pop(stack, line_number);
}

