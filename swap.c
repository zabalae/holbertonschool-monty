#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to linked list stack
 * @line_number: file's line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *next_element;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: cant't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top && top->next)
	{
		next_element = top->next;
		if (next_element->next)
		{
			next_element->next->prev = top;
		}

		top->next = next_element->next;
		next_element->prev = NULL;
		next_element->next = top;
		top->prev = next_element;
		*stack = next_element;
	}
}
