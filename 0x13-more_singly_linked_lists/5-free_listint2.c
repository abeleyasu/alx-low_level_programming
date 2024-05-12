#include "lists.h"

/**
 * free_listint2 - frees a listint_t list
 * @head: double pointer to the beginning of the list
 *
 * Description: function that frees a listint_t list and sets the head to NULL
 * Return: void
 */
void free_listint2(listint_t **head)
{
    listint_t *current;

    if (head == NULL)
        return;

    while (*head != NULL)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
    }
}
