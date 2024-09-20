#include "lists.h"

/**
 * sum_dlistint - Sums all the data (n) of a dlistint_t linked list
 *
 * @head: Pointer to the head of the doubly linked list
 *
 * Return: Sum of all the data (n) in the list, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	/* Traverse the list and sum the values of the nodes */
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
