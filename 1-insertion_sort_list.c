#include "sort.h"
/**
 *swap - swap the node
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *a = node;

	back->next = a->next;
	if (a->next)
		a->next->prev = back;
	a->next = back;
	a->prev = back->prev;
	back->prev = a;
	if (a->prev)
		a->prev->next = a;
	else
		*list = a;
	return (a);
}
/**
 * insertion_sort_list - sorts a doubly linked list
 *
 * @list: Dobule linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
