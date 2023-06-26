#include "monty.h"

/**
  *f_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */

void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head;
	stack_t *first = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (current->next != NULL)
	{
		current = current->next;
	}

	*head = first->next;
	first->next = NULL;
	current->next = first;
}
