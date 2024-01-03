#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number, char *arg)
{
    /* Example of opcode-function mapping. In a complete implementation,
       this could be a part of a lookup table or similar structure. */
    if (strcmp(opcode, "push") == 0)
      {
        push(stack, line_number, arg);
    }
    else if (strcmp(opcode, "pall") == 0)
      {
        pall(stack, line_number);
    }
    else
      {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

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
	  {
            execute_opcode(opcode, &stack, line_number, arg);
        }
    }

    fclose(file);
    free(line);
    /* Free the stack */
    while (stack != NULL)
      {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return (0);
}
