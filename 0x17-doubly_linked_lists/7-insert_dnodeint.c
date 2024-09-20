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

	/* Handle case for index 0: Insert at the head */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Traverse the list to find the correct position */
	temp = *h;
	while (temp && count < idx - 1)
	{
		temp = temp->next;
		count++;
	}

	/* If temp is NULL or index is out of range, return NULL */
	if (temp == NULL || (temp->next == NULL && count < idx - 1))
		return (NULL);

	/* Handle case for insertion at the end */
	if (temp->next == NULL && count == idx - 1)
		return (add_dnodeint_end(h, n));

	/* Create the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;

	/* Adjust the pointers of the next node if it's not NULL */
	if (temp->next != NULL)
		temp->next->prev = new_node;

	temp->next = new_node;

	return (new_node);
}
