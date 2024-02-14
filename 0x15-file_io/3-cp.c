#include "holberton.h"

/**
  * error_argc - Return the error 97.
  * Return: void.
  */
void error_argc(void)
{
	write(STDERR_FILENO, "Usage: cp file_from file_to\n", 28);
	exit(97);
}
/**
  * error_filefrom - Return the error 98.
  * @file: Name of the file.
  * Return: void.
  */
void error_filefrom(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}
/**
  * error_fileto - Return the error.
  * @file: Name of the file.
  * Return: void.
  */
void error_fileto(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}
/**
  * main - Copie a file to another.
  * @argc: Number of arguments.
  * @argv: Name of the files.
  * Return: Always 0.
  */
int main(int argc, char *argv[])
{
	int out_openff, out_openft, out_readff, out_write, out_closeff, out_closeft;
	char buffer[1024];

	if (argc != 3)
		error_argc();
	if (argv[1] == NULL)
		error_filefrom(argv[1]);
	out_openff = open(argv[1], O_RDONLY);
	if (out_openff == -1)
		error_filefrom(argv[1]);
	out_openft = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (out_openft == -1)
		error_fileto(argv[2]);
	out_readff = read(out_openff, buffer, 1024);
	if (out_readff == -1)
		error_filefrom(argv[1]);
	out_write = write(out_openft, buffer, out_readff);
	if (out_write == -1)
		error_fileto(argv[2]);
	while (out_readff == 1024)
	{
		out_readff = read(out_openff, buffer, 1024);
		if (out_readff == -1)
			error_filefrom(argv[1]);
		out_write = write(out_openft, buffer, out_readff);
		if (out_write == -1)
			error_fileto(argv[2]);
	}
	out_closeft = close(out_openft);
	if (out_closeft == -1)
	{dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", out_openft);
		exit(100);
	}
	out_closeff = close(out_openff);
	if (out_closeff == -1)
	{dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", out_openff);
		exit(100);
	}
	return (0);
}




