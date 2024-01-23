#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm
 * @list: is a pointer to a pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *inserted, *temp;

	if (!(*list) || !(*list)->next || !list)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		inserted = current->prev;
		while (inserted != NULL && inserted->n > current->n)
		{
			temp = inserted->prev;

			if (inserted->prev != NULL)
				inserted->prev->next = current;
			current->prev = temp;
			inserted->prev = current;
			inserted->next = current->next;
			current->next = inserted;

			if (inserted->next != NULL)
				inserted->next->prev = inserted;

			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;

			print_list(*list);
			inserted = temp;
		}
		current = current->next;
	}
}
