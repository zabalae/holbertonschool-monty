#include "monty.h"

/**
 * exe - Executes the opcode functions.
 * @opcode: The opcode to execute.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file where the opcode is.
 * @arg: Argument for the opcode.
 * Return: void
 */

void exe(char *opcode, stack_t **stack, unsigned int line_number, char *arg)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Entry point for the Bytecode interpreter.
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 * Return: 0 on success, EXIT_FAILURE on failure.
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode;
		char *arg;

		line_number++;
		opcode = strtok(line, " \n\t");
		arg = strtok(NULL, " \n\t");
		if (opcode)
			exe(opcode, &stack, line_number, arg);
	}
	fclose(file);
	free(line);

	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	return (0);
}
