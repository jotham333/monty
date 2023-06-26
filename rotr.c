#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @head: head of the stack
 * @counter: line number
 * Return: no return
 */

void rotr(stack_t **head, unsigned int counter)
{
	stack_t *last;
	stack_t *second_last;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	last = *head;
	second_last = NULL;

	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	last->prev = NULL;
	second_last->next = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
}
