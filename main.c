#include "monty.h"

GlobalVar globalVar = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 *
 * @argc: argument counter
 *
 * @argv: arguement vector
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	FILE *file;
	size_t len = 0;
	ssize_t readline = 1;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	globalVar.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readline != -1)
	{
		line = NULL;
		readline = getline(&line, &len, file);
		globalVar.content = line;
		line_number++;
		if (line[0] == '#')
			continue;
		if (readline > 0)
		{
			execute(line, &stack, line_number, file);
		}
		free(line);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
