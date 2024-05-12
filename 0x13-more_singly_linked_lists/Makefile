CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

SRC_FILES = 103-main.c 2-add_nodeint.c 101-print_listint_safe.c 102-free_listint_safe.c 103-find_loop.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: o

o: $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@

clean:
	$(RM) $(OBJ_FILES) o
