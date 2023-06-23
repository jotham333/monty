#include "monty.h"
GlobalVar globalVar = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 *
 * @argc: argument counter
 *
 * @argv: arguement vector
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t readline = 1;
	unsigned int count = 0;
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
		content = NULL;
		readline = getline(&content, &size, file);
		globalVar.content = content;
		count++;
		if (readline > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);

	return (0);
}
