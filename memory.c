#include "monty.h"

/**
 * my_malloc - Function to allocate memory
 *
 * @size: amount of memory to be allocated
 *
 * Return: pointer to the allocate memory
 */
void *my_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/**
 * free_stack - Function to free the stack
 *
 * @stack: stack
 *
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL; /**Set the original stack pointer to NULL */
}

