#include "sort.h"

/**
 * swap_nodes - swaps nodes
 * @head: pointer to a pointer
 * @node1: pointer to a pointer
 * @node2: a pointer
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: a pointer to a pointer
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insertion = current->prev;
		while (insertion != NULL && current->n < insertion->n)
		{
			swap_nodes(list, &insertion, current);
			print_list((const listint_t *)*list);
		}
	}

}
