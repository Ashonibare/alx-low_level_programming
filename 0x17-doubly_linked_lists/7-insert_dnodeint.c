#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * in a doubly linked list.
 *
 * @h: Double pointer to the head of the list
 * @idx: Index at which to add the new node (starting from 0)
 * @n: Data (integer) to insert into the new node
 *
 * Return: pointer to the new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *new;
	size_t count = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (count = 0; count < idx; count++)
	{
		if (temp == NULL)
			return (NULL);
		temp = temp->next;

	}

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL)

	new->n = n;
	new->prev = temp;
	new->next = temp->next;
	temp->next->prev = new;
	temp->next = new;

	return (new);
}
