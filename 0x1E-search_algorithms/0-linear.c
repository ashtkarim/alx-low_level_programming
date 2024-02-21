#include "search_algos.h"
/**
 * linear_search - Searches for a value in an array of integers
 * using the Linear search algorithm
 * @array: pointer to array to search in
 * @size: size of the array
 * @value: value to search for
 *
 * Return: -1 OR first index where value is located
 **/
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
