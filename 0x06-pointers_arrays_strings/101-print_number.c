#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */
void print_number(int n)
{
    int divisor = 1;
    int num = n;

    if (num < 0)
    {
        _putchar('-');
        num = -num;
    }

    while (num / divisor >= 10)
        divisor *= 10;

    while (divisor != 0)
    {
        _putchar((num / divisor) % 10 + '0');
        divisor /= 10;
    }
}
