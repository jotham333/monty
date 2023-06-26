#include "monty.h"

/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_div(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int size = 0, temp;

	ptr = *head;

	while (ptr != NULL)
	{
		ptr = ptr->next;
		size++;
	}

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = ptr->next->n / ptr->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}



/**
 * f_mod - computes the remain of division between second
 * topmost by the topmost element
 *
 * @head:stack head
 *
 * @counter:line number
 *
 * Return: no return
 */

void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *ptr = *head;
	int size = 0, temp;

	while (ptr != NULL)
	{
		ptr = ptr->next;
		size++;
	}

	if (size < 2)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = ptr->next->n % ptr->n;
	ptr->next->n = temp;
	*head = ptr->next;
	free(ptr);
}




/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *ptr;

	ptr = *head;

	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (ptr->n > 127 || ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pcha, value out ofrange\n", counter);
		fclose(globalVar.file);
		free(globalVar.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ptr->n);
}
