#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list.
 * @list: a pointer to a pointer to the head of the linked list.
 * @node1: the first node to be swapped.
 * @node2: the second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	if (node1 == NULL || node2 == NULL)
		return;

	temp = node1->prev;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = temp;
	if (temp != NULL)
		temp->next = node2;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev == NULL)
		(*list) = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Shaker Sort algorithm.
 * @list: a pointer to a pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	start = end = NULL;
	while (swapped)
	{
		swapped = 0;
		current = *list;
		/* Move from left to right (forward) */
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		end = current;
		if (!swapped)
			break;
		swapped = 0;
		/* Move from right to left (backward) */
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current;
	}
}
