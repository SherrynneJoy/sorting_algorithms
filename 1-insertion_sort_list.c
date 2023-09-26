#include <stdio.h>
#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: list being sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *srt = NULL, *curr = *list, *temp, *key, *next;

	while (curr != NULL)
	{
		next = curr->next;
		if (srt == NULL || srt->n > curr->n)
		{
			curr->next = srt;
			srt = curr;
		}
		else
		{
			key = srt;
			while (key->next != NULL && key->next->n <= curr->n)
				key = key->next;
			if (key->next == NULL)
			{
				key->next = curr;
				curr->prev = key;
				curr->next = NULL;
			}
			else
			{
				temp = key->next;
				key->next = curr;
				curr->prev = key;
				curr->next = temp;
				temp->prev = curr;
			}
			print_list(*list);
		}
		curr = next;
		print_list(*list);
	}
	*list = srt;
}
