#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * 
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
size_t print_listint_safe(const listint_t *head);
listint_t *add_nodeint(listint_t **head, const int n);

#endif /* LISTS_H */
