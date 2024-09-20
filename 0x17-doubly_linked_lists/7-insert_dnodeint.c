#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * in a doubly linked list.
 *
 * @h: Double pointer to the head of the list
 * @idx: Index at which to add the new node (starting from 0)
 * @n: Data (integer) to insert into the new node
 *
 * Return: Address of the new node, or NULL if it fails or if the index
 * is out of range.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int count = 0;

	/* If inserting at the head (index 0) */
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;

	/* Traverse the list to find the insertion point */
	while (temp && count < idx - 1)
	{
		temp = temp->next;
		count++;
	}

	/* If temp is NULL, the index is out of range */
	if (temp == NULL)
		return (NULL);

	/* Insert in the middle */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;

	/* Update next node's prev if not inserting at the end */
	if (temp->next != NULL)
		temp->next->prev = new_node;

	temp->next = new_node;

	return (new_node);
}
