#include "monty.h"

/**
 * op_div - function to divide elements in the stack
 *
 * @stack: stack
 * @line_number: line number
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	/**Check if the stack contains at least two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Check if the top element of the stack is not zero */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Divide the second top element by the top element of the stack */
	(*stack)->next->n /= (*stack)->n;

	/** Remove the top element */
	op_pop(stack, line_number);
}

/**
 * op_mul - Function to handle the "mul" opcode
 *
 * @stack: stack
 * @line_number: line number
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	/** Check if the stack contains at least two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/**Multiply the second top element by the top element of the stack */
	(*stack)->next->n *= (*stack)->n;

	/** Remove the top element */
	op_pop(stack, line_number);
}

