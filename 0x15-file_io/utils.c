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
