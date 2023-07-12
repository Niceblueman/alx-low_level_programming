#include "main.h"

/**
 * handle_errors_0 - a function that handles errors
 * @a: value to check
 * Return: void
 */
void handle_errors_0(int a)
{
	if (a != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}
/**
 * handle_errors_1 - a function that handles errors
 * @a: value to check
 * @file: file
 * @argv: arguments values
 * Return: void
 */
void handle_errors_1(int a, char *argv[], int file)
{
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		if (file != -1)
			close(file);
		exit(98);
	}
}
/**
 * handle_errors_2 - a function that handles errors
 * @a: value to check
 * @argv: arguments values
 * Return: void
 */
void handle_errors_2(int a, char *argv[])
{
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - cp function clone in C
 * @argc: argument count
 * @argv: arguments values
 * Return: 0 on success or -1 if faild
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t read_bytes, write_bytes;
	char buffer[BUFFER_SIZE];

	handle_errors_0(argc);
	fd_from = open(argv[1], O_RDONLY);
	handle_errors_1(fd_from, argv, -1);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
		O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	handle_errors_1(fd_to, argv, fd_from);
	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes != read_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			if (fd_from != -1)
				close(fd_from);
			if (fd_to != -1)
				close(fd_to);
			exit(99);
		}
	}
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}
