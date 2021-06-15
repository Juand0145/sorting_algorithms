#include "sort.h"

/**
 * shell_sort - is an in-place comparison sort. It can be seen
 * as either a generalization of sorting by exchange (bubble sort)
 * or sorting by insertion (insertion sort)
 * @array: The array of numbers to be sorted
 * @size: The size of the array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t n, i, j;
	int swap;

	if (array == NULL || size < 2)
		return;

	n = 0;

	while (n < size)
		n = n * 3 + 1;

	for (n = (n - 1) / 3; n > 0; n = (n - 1) / 3)
	{
		for (i = n ; i < size; i++)
		{
			swap = array[i];
			for (j = i; j >= n && swap <= array[j - n]; j = j - n)
				array[j] = array[j - n];

			array[j] = swap;
		}
		print_array(array, size);
	}
}
