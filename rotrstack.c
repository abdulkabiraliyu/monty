#include "monty.h"

/**
 * op_rotr - Function to handle the "rotr" opcode
 *
 * @stack: stack
 * @line_number: line numebr
 *
 */
void op_rotr(stack_t **stack, unsigned int line_number)
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

		/** Rotate the stack to the bottom */
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

/**
 * op_stack - Function to handle the "stack" opcode
 *
 * @stack: stack
 * @line_number: line number
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/** Set the current mode to stack */
	current_mode = STACK_MODE;
}

/**
 * op_queue - Function to handle the "queue" opcode
 *
 * @stack: stack
 * @line_number: line numebr
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	/** Set the current mode to queue */
	current_mode = QUEUE_MODE;

	(void)line_number;

	/** Reverse the stack to switch from stack to queue */
	if (*stack != NULL)
	{
		stack_t *prev = NULL;
		stack_t *current = *stack;
		stack_t *next = NULL;

		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		*stack = prev;
	}
}

