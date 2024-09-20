#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * in a doubly linked list.
 *
 * @h: Double pointer to the head of the list
 * @idx: Index at which to add the new node (starting from 0)
 * @n: Data (integer) to insert into the new node
 *
 * Return: Pointer to the new node, or NULL if it fails or if the index
 * is out of range.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *new;
	unsigned int count = 0;

	/* Handle case for index 0: Insert at the head */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Traverse to the node just before the index */
	for (count = 0; count < idx - 1; count++)
	{
		if (temp == NULL)
			return (NULL);
		temp = temp->next;
	}

	/* Handle case for insertion at the end */
	if (temp == NULL)
		return (NULL);  /* idx is out of range */

	/* Create the new node */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);  /* Memory allocation failed */

	new->n = n;
	new->prev = temp;
	new->next = temp->next;

	/* Adjust pointers for the next node, if it exists */
	if (temp->next != NULL)
		temp->next->prev = new;

	temp->next = new;

	return (new);
}
