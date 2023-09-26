#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: a pointer to a pointer
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *insert;
	listint_t *next_node;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current != NULL)
	{
		insert = current->prev;
		next_node = current->next;

		while (insert != NULL && insert->n > current->n)
		{
			insert = insert->prev;
		}
		if (insert == current->prev)
		{
			current = next_node;
			continue;
		}
		if (current->next != NULL)
		{
			current->next->prev = current->prev;
		}
		current->prev->next = current->next;
		if (insert == NULL)
		{
			current->next = (*list);
			current->prev = NULL;
			(*list)->prev = current;
			*list = current;
		}
		else
		{
			current->next = insert->next;
			current->prev = insert;
			if (insert->next != NULL)
			{
				insert->next->prev = current;
			}
			insert->next = current;
		}
		tmp = *list;
		while (tmp != NULL)
		{
			print_list((const listint_t *)*list);
			tmp = tmp->next;
		}
		current = next_node;
	}
}
