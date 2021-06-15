#include "sort.h"
/**
 * selection_sort -  selection sort is an in-place comparison sorting
 * algorithm. It has an O(n2) time complexity,
 * which makes it inefficient on large lists
 * @array: pointer to array
 * @size: size of array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, swap, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1;  j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (i != min)
		{
			swap = array[min];
			array[min] = array[i];
			array[i] = swap;
			print_array(array, size);
		}
	}

}
