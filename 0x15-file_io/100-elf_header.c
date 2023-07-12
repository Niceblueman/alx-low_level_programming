#include "main.h"

/**
 * check_elf - ...
 * @v: ...
 * Description: ...
 */
void check_elf(unsigned char *v)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (v[index] != 127 &&
			v[index] != 'E' &&
			v[index] != 'L' &&
			v[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * flushmagic - ...
 * @v: ...
 *
 * Description: ...
 */
void flushmagic(unsigned char *v)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", v[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * flushclass - ...
 * @v: ...
 */
void flushclass(unsigned char *v)
{
	printf("  Class:                             ");

	switch (v[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", v[EI_CLASS]);
	}
}

/**
 * flushversion - ...
 * @v: ...
 */
void flushversion(unsigned char *v)
{
	printf("  Version:                           %d",
		   v[EI_VERSION]);

	switch (v[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * flushdata - ...
 * @v: ...
 */
void flushdata(unsigned char *v)
{
	printf("  Data:                              ");

	switch (v[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", v[EI_CLASS]);
	}
}
#include "main.h"

/**
 * flushosabi - Prints the OS/ABI of an ELF header.
 * @v: A pointer to an array containing the ELF version.
 */
void flushosabi(unsigned char *v)
{
	printf("  OS/ABI:                            ");

	switch (v[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", v[EI_OSABI]);
	}
}

/**
 * flushabi - Prints the ABI version of an ELF header.
 * @v: A pointer to an array containing the ELF ABI version.
 */
void flushabi(unsigned char *v)
{
	printf("  ABI Version:                       %d\n",
		   v[EI_ABIVERSION]);
}

/**
 * flushtype - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @v: A pointer to an array containing the ELF class.
 */
void flushtype(unsigned int e_type, unsigned char *v)
{
	if (v[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * flushentry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @v: A pointer to an array containing the ELF class.
 */
void flushentry(unsigned long int e_entry, unsigned char *v)
{
	printf("  Entry point address:               ");
	if (v[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (v[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - a program that displays the information contained
 * in the ELF header at the start of an ELF file.
 * @argc: arguments count
 * @argv: arguments values
 * Return: 0 on success -1 if faild.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	flushmagic(header->e_ident);
	flushclass(header->e_ident);
	flushosabi(header->e_ident);
	flushdata(header->e_ident);
	flushversion(header->e_ident);
	flushabi(header->e_ident);
	flushtype(header->e_type, header->e_ident);
	flushentry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
