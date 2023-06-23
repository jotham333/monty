#include "monty.h"

/* Stack opcodes */
static struct
{
	const char *opcode;
	void (*func)(stack_t **, unsigned int);
} opcodes[] = {
	{"push", f_push},
	{"pall", f_pall},
	{"pint", f_pint},
	{"pop", f_pop},
	{"swap", f_swap},
	{"add", f_add},
	{"nop", f_nop},
	{NULL, NULL}};

/**
 * execute - executes the instructions in the file
 * @content: content of the file
 * @stack: stack head
 * @counter: current line number
 * @file: file to execute
 * Return: 0
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	char opcode[MAX_OPCODE_LEN] = {0};
	char arg[MAX_ARG_LEN] = {0};
	int i;

	/* Parse the opcode */
	sscanf(content, "%s", opcode);

	/* Parse the argument */
	sscanf(content, "%*s%s", arg);

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			globalVar.arg = arg;
			opcodes[i].func(stack, counter);
			return (0);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
