#include "sort.h"

/**
 * selection_sort - selection algorthms
 * @size: size input
 * @array: pointer input
 * Return: No Return
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, jMin, swap;

	/* array[0] to a[size-1] is the array to sort. */
	/* advance the position through the entire array */
	for (i = 0; i < size - 1; i++)
	{
		/* find the min element in the unsorted array[i .. size-1] */
		/* assume the min is the first element */
		jMin = i;
		/* test against elements after i to find the smallest */
		for (j = i + 1; j < size; j++)
		{
			/* if this element is less, then it is the */
			/*new minimum */
			if (array[j] < array[jMin])
			{
				/* found new minimum; remember its index */
				jMin = j;
			}
		}
		if (jMin != i)
		{
			swap = array[jMin];
			array[jMin] = array[i];
			array[i] = swap;
			/* swap(array[i], array[jMin]); */
			print_array(array, size);
		}
	}
}
