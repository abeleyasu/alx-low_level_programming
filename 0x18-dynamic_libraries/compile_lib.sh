#!/bin/bash

# Compile the functions into object files
gcc -c -Wall -Werror -fpic functions.c

# Create the dynamic library from the object files
gcc -shared -o libdynamic.so functions.o

# Clean up the object files
rm functions.o
