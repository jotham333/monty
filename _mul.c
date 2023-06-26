#include "monty.h"

/**
 * f_mul - multiply the top two elements of the stack
 * @head: the stack head
 * @counter: current line number in the Monty program
 * Return: nothing
 */

void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	temp = ptr->next->n *= ptr->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}
