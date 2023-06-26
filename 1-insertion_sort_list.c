#include "sort.h"

/**
 * listlen - returns the length of the doubly linked list
 * @h: pointer to the head of the list
 * Return: length of the list
 */
int listlen(listint_t *h)
{
	int length = 0;

	while (h != NULL)
	{
		length++;
		h = h->next;
	}
	return (length);
}

/**
 * insertion_sort_list - sorts a d linked list of ints in ascending O
 * @list: double pointer to the list to be sorted
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *_1 = NULL;
	listint_t *_2 = NULL, *_3 = NULL, *_4 = NULL;

	if (!list || !(*list) || listlen(*list) < 2)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->n < curr->prev->n)
		{
			_1 = curr->prev->prev;
			_2 = curr->prev;
			_3 = curr;
			_4 = curr->next;

			_2->next = _4;
			if (_4)
				_4->prev = _2;
			_3->next = _2;
			_3->prev = _1;
			if (_1)
				_1->next = _3;
			else
				*list = _3;
			_2->prev = _3;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}
