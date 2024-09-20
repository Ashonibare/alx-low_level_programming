#include "lists.h"
/**
 * dlistint_len - prints all elements of a dlistint_t list
 *
 * @h: the head pointer of the list
 *
 * Return: number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t element_no = 0;

	while (h)
	{
		++element_no;
		h = h->next;
	}

	return (element_no);
}
