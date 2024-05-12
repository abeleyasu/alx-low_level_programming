#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: the length of s
 */
int _strlen(char *s)
{
    if (*s == '\0')
        return (0);
    return (1 + _strlen(s + 1));
}

/**
 * is_palindrome_util - checks if a string is a palindrome
 * @s: the string
 * @i: the start index
 * @j: the end index
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome_util(char *s, int i, int j)
{
    if (i >= j)
        return (1);
    if (s[i] != s[j])
        return (0);
    return (is_palindrome_util(s, i + 1, j - 1));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = _strlen(s);

    return (is_palindrome_util(s, 0, len - 1));
}
