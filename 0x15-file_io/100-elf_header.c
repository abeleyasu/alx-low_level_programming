#include "main.h"
#include <stdio.h> // Include stdio.h for fprintf function

/**
 * read_elf_header - reads ELF header and prints it
 * @elf_fd: ELF file descriptor
 * @elf_filename: name of ELF file
 */
void read_elf_header(int elf_fd, char *elf_filename)
{
    Elf64_Ehdr elf_header;
    ssize_t bytes_read;

    bytes_read = read(elf_fd, &elf_header, sizeof(Elf64_Ehdr));
    if (bytes_read < (ssize_t)sizeof(Elf64_Ehdr))
    {
        fprintf(stderr, "read error: cannot read ELF header from file %s\n", elf_filename);
        exit(98);
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "%s: Error: Not an ELF file\n", elf_filename);
        exit(98);
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (size_t i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", elf_header.e_ident[i], i + 1 == EI_NIDENT ? '\n' : ' ');

    printf("  Class:                             %s\n",
           elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "Unknown");
    printf("  Data:                              %s\n",
           elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           elf_header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown");
    printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n",
           elf_header.e_ident[EI_OSABI] == ELFOSABI_NONE ? "UNIX - System V" :
           elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
           elf_header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
           elf_header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
           elf_header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
           "Unknown");
    printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (elf_header.e_type)
    {
    case ET_NONE:
        printf("No file type\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", elf_header.e_type);
        break;
    }

    printf("  Entry point address:               %#lx\n", (unsigned long)elf_header.e_entry);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
    int elf_fd;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return (98);
    }

    elf_fd = open(argv[1], O_RDONLY);
    if (elf_fd == -1)
    {
        fprintf(stderr, "open error: cannot open file %s\n", argv[1]);
        return (98);
    }

    read_elf_header(elf_fd, argv[1]);

    if (close(elf_fd) == -1)
    {
        fprintf(stderr, "close error: cannot close file %s\n", argv[1]);
        return (98);
    }

    return (0);
}

