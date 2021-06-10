#include "sort.h"

/**
 * bubble_sort - is a simple sorting algorithm
 * that repeatedly steps through the list, compares adjacent
 * elements and swaps them
 * @array: The array of numbers to be sorted
 * @size: the size of teh array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, swap, loop;

	if (!array || size < 2)
		return;

	while (loop != 0)
	{
		loop = 0;

		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				loop = 1;

				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
