#include "monty.h"

/**
 * f_pop - prints the top
 *
 * @head: stack head
 *
 * @counter:
 *
 */

void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *ptr = *head;

	if (ptr != NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	*head = ptr->next;
	free(ptr);
}
