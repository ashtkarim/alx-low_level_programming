#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: pointer to the array search in
 * @size: the size of the array
 * @value: the value search for
 *
 * Return: first index where value is located OR -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump;
	size_t prev;
	size_t current;

	if (array == NULL)
		return (-1);

	jump = sqrt(size);
	prev = 0;
	current = jump;

	printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
	while (current < size && array[current] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", current, array[current]);
		prev = current;
		current += jump;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", prev, current);

	if (current >= size)
		current = size - 1;

	while (prev <= current)
	{
		printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);

		prev++;
	}

	return (-1);
}
