#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to linked list stack
 * @line_number: file's line number
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *t = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(t);
}
