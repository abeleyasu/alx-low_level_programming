#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number to add
 * @n2: second number to add
 * @r: buffer to store the result
 * @size_r: buffer size
 *
 * Return: pointer to the result, or 0 if result cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l, m, n;

	for (l = 0; n1[l]; l++)
		;
	for (m = 0; n2[m]; m++)
		;
	if (l > size_r || m > size_r)
		return (0);
	i = l - 1;
	j = m - 1;
	k = 0;
	n = 0;
	while (i >= 0 || j >= 0)
	{
		n += (i >= 0) ? n1[i--] - '0' : 0;
		n += (j >= 0) ? n2[j--] - '0' : 0;
		if (k >= size_r - 1 || (n > 9 && (r[k++] = n % 10 + '0')))
			return (0);
		else if ((n <= 9 && (r[k++] = n + '0')))
			n = 0;
		else
			n /= 10;
	}
	if (n)
	{
		if (k >= size_r - 1)
			return (0);
		r[k++] = n + '0';
	}
	r[k] = '\0';
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		n = r[i];
		r[i] = r[j];
		r[j] = n;
	}
	return (r);
}
