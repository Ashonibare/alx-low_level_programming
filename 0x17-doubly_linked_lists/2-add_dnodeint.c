#include "lists.h"
/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list
 *
 * @head: Double pointer to the head of the doubly linked list
 * @n: Value to insert in the new node
 *
 * Return: Pointer to the new node, or NULL if it fails
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;
	/* Allocate memory for new node */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	/* Initialise new node with given value and point it to the head */
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	/* update the prev. head node's prev. if it exists */
	new->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}

	/* Move the head to point to the new node */
	*head = new;
	return (new);
}
