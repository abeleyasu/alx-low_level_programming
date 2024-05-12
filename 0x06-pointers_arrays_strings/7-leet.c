#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	int i, j;
	char leet_letters[] = "aAeEoOtTlL";
	char leet_numbers[] = "4433007711";

	i = 0;
	while (s[i])
	{
		j = 0;
		while (leet_letters[j])
		{
			if (s[i] == leet_letters[j])
				s[i] = leet_numbers[j];
			j++;
		}
		i++;
	}
	return (s);
}
