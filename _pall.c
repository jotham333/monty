#include "monty.h"

/**
 * f_pall - prints the stack
 *
 * @head: the stack head
 *
 * @counter: not used
 *
 * Return: nothing
 */


void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *ptr = *head;
	(void)counter;

	if (ptr == NULL)
	{
		return;
	}

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
