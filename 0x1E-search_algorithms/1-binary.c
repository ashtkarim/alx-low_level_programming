#include "search_algos.h"

/**
 * print_array - Prints array elemnts
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: void
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: pointer to array to search in
 * @size: size of the array
 * @value: value to search for
 *
 * Return: -1 OR first index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	size_t start_idx = 0;
	size_t end_idx = size - 1;
	size_t mid_idx;

	if (!array)
		return (-1);

	while (start_idx <= end_idx)
	{
		print_array(array + start_idx, end_idx - start_idx + 1);
		mid_idx = start_idx + ((end_idx - start_idx) / 2);

		if (value == array[mid_idx])
			return (mid_idx);
		else if (value > array[mid_idx])
			start_idx = mid_idx + 1;
		else
			end_idx = mid_idx - 1;
	}

	return (-1);
}
