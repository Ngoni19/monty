#include "monty.h"
/**
 * add_end_node - add node to front of doubly-linked-list
 * @h: pointer to head of list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */
int add_end_node(stack_t **h, int n)
{
	stack_t *new;

	if (!h)
		return (-1);

	/*set new node data and malloc */
	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new->n = n;

	/* do something for empty linked list */
	if (*h == NULL)
	{
		*h = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else /* insert data to front */
	{
		new->next = *h;
		(*h)->prev = new;
		*h = new;
	}
	return (0);
}
/**
 * delete_end_node - deletes node at end of doubly linked list
 * @h: pointer to head of doubly linked list
 */
void delete_end_node(stack_t **h)
{
	stack_t *del = NULL;

	/* do something for only one node in list */
	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else /* else delete front, and link*/
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}
/**
 * free_dlist - frees a doubly-linked list
 * with only int data (no strings)
 * @h: pointer to head of list
 */
void free_dlist(stack_t **h)
{
	/* return when empty-list */
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
