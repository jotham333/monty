#include "monty.h"

/**
 * f_pint - prints the stack
 * @head: the stack head
 * @number: not used
 * Return: nothing
 */

void f_pint(stack_t **head, unsigned int number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);

	free_stack(*head);
	free(globalVar.content);
	fclose(globalVar.file);
}
