#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int is_integer(const char *arg)
{
    if (arg == NULL)
        return 0;
    if (*arg == '-' || *arg == '+') 
        arg++;
    while (*arg) {
        if (!isdigit(*arg))
            return 0;
        arg++;
    }
    return (1);
}
