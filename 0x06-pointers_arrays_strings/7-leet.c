#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @s: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *s)
{
    int i, j;
    char leet[] = {'4', '3', '0', '7', '1'};
    char letters[] = {'a', 'e', 'o', 't', 'l', 'A', 'E', 'O', 'T', 'L'};

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (s[i] == letters[j])
            {
                s[i] = leet[j / 2];
                break;
            }
        }
    }

    return (s);
}
