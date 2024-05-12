#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @s: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *s)
{
    char *start = s;
    char *rot = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    int i;

    while (*s)
    {
        if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
        {
            i = (*s >= 'A' && *s <= 'Z') ? *s - 'A' : *s - 'a' + 26;
            *s = rot[i];
        }
        s++;
    }

    return start;
}
