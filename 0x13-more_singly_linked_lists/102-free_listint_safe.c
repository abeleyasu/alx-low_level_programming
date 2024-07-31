#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list, handling loops
 * @h: double pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *temp;
    listint_t *visited[1024]; /* This is a simplistic way to track visited nodes */
    size_t i;

    if (!h || !*h)
        return (0);

    while (*h)
    {
        for (i = 0; i < count; i++)
        {
            if (*h == visited[i])
            {
                *h = NULL;
                return (count);
            }
        }
        
        visited[count++] = *h;
        temp = (*h)->next;
        free(*h);
        *h = temp;
    }

    *h = NULL;
    return (count);
}
