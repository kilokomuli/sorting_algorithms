#include "sort.h"
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *now;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (now = *list; now->next != NULL; now = now->next)
		{
			if (now->n > now->next->n)
			{
				swap_nodes(list, now, now->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; now->prev != NULL; now = now->prev)
		{
			if (now->n < now->prev->n)
			{
				swap_nodes(list, now->prev, now);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: Double pointer to the heaad of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
