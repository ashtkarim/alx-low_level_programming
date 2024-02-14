#include "holberton.h"
/**
  * _strlen - Return the len of a string.
  * @s: The string.
  * Return: Lenght of a string.
  */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
  * create_file - Write a string in a new file.
  * @filename: Name of the file.
  * @text_content: String into the file.
  * Return: 1 if works, -1 if doesn't.
  */
int create_file(const char *filename, char *text_content)
{
	int out_write, out_open;

	if (filename == NULL)
		return (-1);


	out_open = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (out_open == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(out_open);
		return (1);
	}

	out_write = write(out_open, text_content, _strlen(text_content));
	if (out_write == -1)
	{
		close(out_open);
		return (-1);
	}

	close(out_open);
	return (1);
}
