#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: pointer to the array search in
 * @size: size of the array
 * @value: value to search for
 *
 * Return: first index where value is located OR -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;
	size_t hi_lo;
	int arr_hl;

	if (!array || !value)
		return (-1);

	while (low <= high && array[low] <= value && array[high] >= value)
	{
		hi_lo = high - low;
		arr_hl = array[high] - array[low];
		pos = low + (((double)(hi_lo) / (arr_hl)) * (value - array[low]));

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			low = pos - 1;
		else
			low = pos + 1;
	}

	return (-1);
}
