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
		while (current != NULL)
		{
		inserted = current->prev;
		while (inserted != NULL && inserted->n > current->n)
		{
			temp = inserted;
			inserted = inserted->prev;

			if (inserted != NULL)
				inserted->next = current;
			current->prev = inserted;
			temp->prev = current;
			temp->next = current->next;
			current->next = temp;

			if (temp->next != NULL)
				temp->next->prev = temp;

			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = current->next;
		}
	}
}
