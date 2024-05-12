#ifndef MAIN_H
#define MAIN_H

#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void read_elf_header(int elf_fd, char *elf_filename);

#endif /* MAIN_H */
