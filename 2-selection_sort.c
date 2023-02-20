#include "sort.h"

/**
 * selection_sort - sorts array in ascending order
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, swap;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap = array[min_idx];
			array[min_idx] = array[i];
			array[i] = swap;
			print_array(array, size);
		}
	}
}
