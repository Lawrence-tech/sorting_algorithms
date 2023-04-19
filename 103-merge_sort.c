#include "sort.h"
#include <stdlib.h>
/**
 * merge_subarrays - merge the subarrays
 * @a: subarray to merge
 * @b: stores the merged subarray
 * @left: beginning of each subarray
 * @mid: the mid
 * @right: end of each subarray
 *
 * Return: nothing
 */

void merge_subarrays(int *a, int *b, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid + 1;
	size_t k = left;

	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > mid)
	{
		while (j <= right)
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			b[k] = a[i];
			i++;
			k++;
		}
	}

	for (k = left; k <= right; k++)
	{
		a[k] = b[k];
	}
}

/**
 * merge_sort_subarr - Divides array into subarrays until one element is left
 * @subarr: the array to divide
 * @buff: a buffer to store the subarray
 * @left: the left of the array, the beginning of the subarray
 * @right: the right of the array, the end of the subarray
 *
 * Return: nothing
 */
void merge_sort_subarr(int *subarr, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = (left + (right - left)) / 2;
		merge_sort_subarr(subarr, buff, left, mid);
		merge_sort_subarr(subarr, buff, mid, right);
		merge_subarrays(subarr, buff, left, mid + 1, right);
	}
}

/**
 * merge_sort - sorts an array of intergers in ascending order using top-down
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_subarr(array, buff, 0, size - 1);

	free(buff);
}
