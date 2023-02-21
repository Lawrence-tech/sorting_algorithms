#include "sort.h"

/**
  * swap - swaps the elements
  * @ptr1: pointer to the first element
  * @ptr2: pointer to the other element
  *
  * Return: nothing
 */
void swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

/**
 * shell_sort - sorts an array in asceding order using knut sequence
 * @array: array to sort
 * @size: size of the array
 *
 * Return nothing
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(&array[j], &array[j - gap]);
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
