#include "monty.h"

/**
 * pall - prints all the values to the stack
 * @stack: pointer to the linked list stack
 * @line_number: file's line number
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
