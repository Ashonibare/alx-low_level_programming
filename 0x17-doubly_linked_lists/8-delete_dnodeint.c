#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a specified index
 * in a doubly linked list.
 *
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete (starting from 0)
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;

	/* Handle the case where the list is empty */
	if (*head == NULL)
		return (-1);

	/* Traverse to the desired index */
	for (; index != 0; index--)
	{
		if (temp == NULL)  /* Ensure we don't go past the end of the list */
			return (-1);
		temp = temp->next;
	}

	/* If the node to delete is the head node */
	if (temp == *head)
	{
		*head = temp->next;  /* Move head to the next node */
		if (*head != NULL)
			(*head)->prev = NULL;  /* Update the new head's prev pointer */
	}
	else
	{
		/* Link previous node to next node */
		temp->prev->next = temp->next;

		/* Link next node to previous node if it exists */
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
	}

	/* Free the memory of the deleted node */
	free(temp);
	return (1);
}
