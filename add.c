#include "monty.h"

/**
 * add - adds the top two elements
 * @stack: pointer to linked list stack
 * @line_number: file's line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = top->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n += top->n;
	*stack = second;
	second->prev = NULL;

	free(top);
}
