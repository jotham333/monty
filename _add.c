#include "monty.h"

/**
 * f_add - adds the top two elements of the stack
 *
 * @head: the stack head
 *
 * @counter: the counter
 *
 * Return: no return
 */

void f_add(stack_t **head, unsigned int counter)
{
	stack_t *ptr = *head;
	int len = 0, temp;

	while (ptr != NULL && ptr->next != NULL)
	{
		ptr = ptr->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = ptr->n + ptr->next->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}
