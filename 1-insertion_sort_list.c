#include "sort.h"
#include <stdio.h>

/**
* insertion_sort_list - Sorts a doubly linked list of integers in
*                       ascending order using the insertion sort algorithm.
* @list: Pointer to the head of the doubly linked list.
*
* Return: No return value.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	current = (*list)->next;

	while (current)
	{
		temp = current->prev;

		while (temp && temp->n > current->n)
		{
			if (temp->prev)
				temp->prev->next = current;
			else
				*list = current;

			if (current->next)
				current->next->prev = temp;

			temp->next = current->next;
			current->prev = temp->prev;
			current->next = temp;
			temp->prev = current;

			temp = current->prev;
			print_list(*list);
		}
		current = current->next;
	}

}
