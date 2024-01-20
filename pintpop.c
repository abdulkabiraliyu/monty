#include "monty.h"

/**
 * op_pint - function to handle the "pint" opcode
 *
 * @stack: pointer to stack pointers
 * @line_number: line number
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	/** Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Print the value at the top of the stack */
	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - Function to handle the "pop" opcode
 *
 * @stack: pointer to stack pointers
 * @line_number: line number
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/** Check if the stack is empty*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** Remove the top element of the stack */
	temp = *stack;
	*stack = temp->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}

