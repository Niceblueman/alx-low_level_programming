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
