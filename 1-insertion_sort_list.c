#include "sort.h"

/**
 * insertion_sort_list - Sort doubly linked list of ints
 *                       in ascending order using Insertion sort algorithm
 *
 * @list: pointer to head of doubly linked list
 *
 * Return: NULL
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
temp->prev->next = temp->next;

if (temp->next != NULL)
temp->next->prev = temp->prev;

temp->next = temp->prev;
temp->prev = temp->prev->prev;
temp->next->prev = temp;

if (temp->prev == NULL)
*list = temp;

print_list(*list);
}

current = current->next;
}
}
