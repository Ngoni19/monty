#include "monty.h"
/**
 * swap - location of prev stack with the top stack
 * @h: node to be swapped
 * @line_number: node number
 */
void swap(stack_t **h, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*h)->next;
	if (temp->next != NULL)
	{
		(*h)->next = temp->next;
		(*h)->next->prev = *h;

	}
	else
	{
		temp->prev->prev = temp;
		temp->prev->next = NULL;
	}
	temp->prev = NULL;
	temp->next = *h;
	(*h) = temp;
}
/**
 * rotl - rotate so top of stack becomes last one
 * second becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotl(stack_t **h, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	if ((*h)->next != NULL)
	{
		temp = *h;
		while (temp->next != NULL)
			temp = temp->next;
		(*h)->prev = temp;
		temp->next = *h;
		(*h)->next->prev = NULL;
		*h = (*h)->next;
		temp->next->next = NULL;
	}
}
/**
 * rotr - rotate only bottom node of stack becomes 1st one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotr(stack_t **h, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	if ((*h)->next != NULL)
	{
		temp = *h;
		while (temp->next != NULL)
			temp = temp->next;
		(*h)->prev = temp;
		temp->next = *h;
		temp->prev->next = NULL;
		temp->prev = NULL;
		(*h) = (*h)->prev;
	}
}
