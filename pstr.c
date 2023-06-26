#include "monty.h"

/**
 * f_pstr - prints the top element of the stack
 * @head: the stack head
 * @counter: current line number in the Monty program
 * Return: nothing
 */

void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *ptr;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't print, stack too short\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	while (*head != NULL)
	{
		ptr = (*head)->next;
		if (ptr->n > 127 || ptr->n < -128)
		{
			fprintf(stderr, "L%d: can't print, value too large\n", counter);
			break;
		}
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}
