#include <unistd.h>

/**
* main - Entry point of the program
*
* Return: Always 1 (Error)
*/
int main(void)
{
/* Message to be printed */
char message[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

/* Write the message to standard error using write system call */
write(2, message, sizeof(message) - 1);

/* Return 1 to indicate an error */
return (1);
}
