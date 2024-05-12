#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store the result
 * @size_r: buffer size
 * Return: pointer to the result, or 0 if result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, carry = 0, sum = 0;
	int i, j;

	while (n1[len1])
		len1++;
	while (n2[len2])
		len2++;

	if (len1 > size_r || len2 > size_r)
		return (0);

	len1--;
	len2--;
	r[size_r] = '\0';
	size_r--;

	for (i = len1, j = len2; i >= 0 || j >= 0; i--, j--)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';
		if (sum > 9)
		{
			carry = 1;
			sum %= 10;
		}
		else
		{
			carry = 0;
		}
		r[size_r] = sum + '0';
		size_r--;
	}

	if (carry)
	{
		if (size_r < 0)
			return (0);
		r[size_r] = '1';
		return (r + size_r);
	}

	return (r + size_r + 1);
}
