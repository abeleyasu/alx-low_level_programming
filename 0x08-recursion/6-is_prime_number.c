#include "main.h"

/**
 * is_prime_util - checks for prime number
 * @n: the number to check
 * @i: the iterator
 * Return: 1 if prime, otherwise 0
 */
int is_prime_util(int n, int i)
{
    if (n <= 1)
        return (0);
    if (i * i > n)
        return (1);
    if (n % i == 0)
        return (0);
    return (is_prime_util(n, i + 1));
}

/**
 * is_prime_number - checks if the input integer is a prime number
 * @n: the number to check
 * Return: 1 if prime, otherwise 0
 */
int is_prime_number(int n)
{
    return (is_prime_util(n, 2));
}
