#include "sort.h"
void cocktail_sort_list(listint_t **list);
void swap_nodes_head(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_nodes_tail(listint_t **list, listint_t **tail, listint_t **shaker);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool swap = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (swap == false)
	{
		swap = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_nodes_head(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swap = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_nodes_tail(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swap = false;
			}
		}
	}
}

/**
 * swap_nodes_head - swaps two nodes in a doubly linked list
 * @list: Double pointer to the heaad of the list
 * @tail: pointer to the tail of the doubly linked list
 * @shaker: pointer to the current node
 */
void swap_nodes_head(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_nodes_tail - swaps two nodes in a doubly linked list
 * @list: Double pointer to the heaad of the list
 * @tail: pointer to the tail of the doubly linked list
 * @shaker: pointer to the current node
 */
void swap_nodes_tail(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}
