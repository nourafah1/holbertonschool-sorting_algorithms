#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* swap nodes */
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->prev->next = temp->next;

			temp->next = temp->prev;
			temp->prev = temp->next->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			temp->next->prev = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
