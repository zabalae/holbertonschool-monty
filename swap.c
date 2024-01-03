#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to linked list stack
 * @line_number: file's line number
 * @Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *t = *stack;
	stack_t *next_node = t->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: cant't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	t->prev = next_node;

	t->next = next_node->next;

	if (next_node-next)
		next_node->next->prev = t;

	next_node->prev = NULL;

	next_node->next = t;

	*stack = next_node;
}
