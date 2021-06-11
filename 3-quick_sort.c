#include "sort.h"

/**
 * print_sort - sort the given array printed
 * and return the pivot
 * @array: The array to sort
 * @low: position of the high sub array
 * @high: position of the high sub array
 * @size: total size of the array
 * Return: The pivot
 */
int print_sort(int *array, int low, int high, size_t size)
{
	int i, j, swap;

	j = low - 1;

	for (i = low; i < high; i++)
	{
		if (array[i] < array[high])
		{
			j++;
			if (j != i)
			{
				swap = array[j];
				array[j] = array[i];
				array[i] = swap;
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[j + 1])
	{
		swap = array[j + 1];
		array[j + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}

	return (j + 1);
}

/**
 * split_array - split the two arrays and keept doint until
 * just have one element
 * @array: The array to sort
 * @low: position of the high sub array
 * @high: position of the high sub array
 * @size: total size of the array
 */
void split_array(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = print_sort(array, low, high, size);
		split_array(array, low, pivot - 1, size);
		split_array(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - is an in-place sorting algorithm
 * @array: The array to sort
 * @size: The size of teh array
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = (int)size - 1;

	split_array(array, low, high, size);
}
