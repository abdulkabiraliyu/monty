#include "monty.h"

/**
 * op_swap - Function to handle the "swap" opcode
 *
 * @stack: stack
 * @line_number: line numebr
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	/** Check if the stack contains at least two elements*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Swap the top two elements of the stack*/
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * op_add - Function to add two elements of the stack
 *
 * @stack: stack
 * @line_number: line numebr
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	/** Check if the stack contains at least two elements*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Swap the top two elements of the stack*/
	(*stack)->next->n += (*stack)->n;

	/** Remove the top element*/
	op_pop(stack, line_number);
}

