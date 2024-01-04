#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to linked list stack
 * @line_number: file's line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = top->next;
	int temp = top->n;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: cant't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->n = second->n;

	second->n = temp;
}
