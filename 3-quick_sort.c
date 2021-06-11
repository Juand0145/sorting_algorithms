#include "sort.h"

/**
 * print_sort - sort the given array printed
 * and return the pivot
 * @array: The array to sort
 * @left: position of the right sub array
 * @right: position of the right sub array
 * @size: total size of the array
 * Return: The pivot
 */
int print_sort(int *array, int left, int right, size_t size)
{
	int i, j, swap;

	j = left - 1;

	for (i = left; i < right; i++)
	{
		if (array[i] < array[right])
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

	if (array[right] < array[j + 1])
	{
		swap = array[j + 1];
		array[j + 1] = array[right];
		array[right] = swap;
		print_array(array, size);
	}

	return (j + 1);
}

/**
 * split_array - split the two arrays and keept doint until
 * just have one element
 * @array: The array to sort
 * @left: position of the right sub array
 * @right: position of the right sub array
 * @size: total size of the array
 */
void split_array(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = print_sort(array, left, right, size);
		split_array(array, left, pivot - 1, size);
		split_array(array, pivot + 1, right, size);
	}
}

/**
 * quick_sort - is an in-place sorting algorithm
 * @array: The array to sort
 * @size: The size of teh array
 */
void quick_sort(int *array, size_t size)
{
	int left, right;

	if (array == NULL || size < 2)
		return;

	left = 0;
	right = (int)size - 1;

	split_array(array, left, right, size);
}
