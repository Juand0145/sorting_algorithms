#include "sort.h"

/**
 * counting_sort - s an algorithm for sorting a collection
 * of objects according to keys that are small integers; that is,
 * it is an integer sorting algorithm
 * @array: Is the nombers we want to sorte
 * @size: the size of the array that will be sorted
 */
void counting_sort(int *array, size_t size)
{
	int i, max_value, *count, *places;
	size_t j, swap, total;

	if (size < 2 || !array)
		return;

	places = malloc(sizeof(int) * size);

	if (!places)
	{
		free(places);
		return;
	}

	max_value = 0;
	for (j = 0; j < size; j++)
	{
		places[j] = array[j];

		if (array[j] > max_value)
			max_value = array[j];
	}

	count = malloc(sizeof(int) * max_value + 1);
	if (!count)
	{
		free(places);
		free(count);
		return;
	}

	for (i = 0; i <= max_value; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[array[j]] += 1;

	total = 0;

	for (i = 0; i <= max_value; i++)
	{
		swap = count[i];
		count[i] = total;
		total += swap;
	}

	for (j = 0; j < size; j++)
	{
		array[count[places[j]]] = places[j];
		count[places[j]] += 1;
	}

	print_array(count, max_value + 1);

	free(count);
	free(places);
}
