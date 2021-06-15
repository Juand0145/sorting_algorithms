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
	size_t i, swap = 1, _switch = 1;

	if (!array || size < 2)
		return;

	while (_switch)
	{
		_switch = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i - 1];
				array[i + 1] = array[i];
				array[i] = swap;
				print_array(array, size);
				_switch = 1;
			}
		}
	}
}
