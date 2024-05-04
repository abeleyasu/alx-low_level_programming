#!/bin/bash
gcc -c *.c -Wall -Werror -Wextra -pedantic
ar -rc liball.a *.o
