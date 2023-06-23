#include "monty.h"

/**
 * f_push - pushes an element onto the stack or queue
 * @head: pointer to the head of the stack or queue
 * @counter: current line number in the Monty program
 */
void f_push(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int n;

	if (globalVar.arg == NULL || (!isdigit(*globalVar.arg)
	&& *globalVar.arg != '-'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(globalVar.arg);
	ptr = malloc(sizeof(stack_t));

	if (globalVar.is_stack == 0)
	{
		ptr->n = n;
		ptr->next = *head;
		*head = ptr;
	}
	else
	{
		ptr->n = n;
		ptr->prev = NULL;
		ptr->next = *head;
		*head = ptr;
	}

	fclose(globalVar.file);
	free(globalVar.content);
}
