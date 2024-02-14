#include "holberton.h"

/**
  * read_textfile - Read a text in a file and print it.
  * @filename: Name of the file.
  * @letters: Number of letters.
  * Return: Always 0.
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, tmp, out;
	char *content;

	if (filename == NULL)
		return (0);

	content = malloc(letters * sizeof(char));
	if (content == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	tmp = read(fd, content, letters);
	if (tmp == -1)
	{
		close(fd);
		free(content);
		return (0);
	}

	out = write(STDOUT_FILENO, content, tmp);
	if (out == -1)
	{
		close(fd);
		free(content);
		return (0);
	}
	close(fd);
	free(content);

	return (out);
}
