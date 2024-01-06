#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the linked list stack
 * @line_number: file's line number
 * @arg: The value to be pushed to the stack.
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *new_node;
	int num;

	if (!is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * is_integer - ....
 * @arg: .....
 * Return: .....
 */

int is_integer(const char *arg)
{
	if (arg == NULL)
		return (0);
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg)
	{
		if (!isdigit(*arg))
			return (0);
	arg++;
	}

	return (1);
}
