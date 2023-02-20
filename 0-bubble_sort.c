#include "sort.h"

void swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}


/**
 * bubble_sort - sorts an array of integers in ascending order
 * @*array: pointer to the array to be sorted
 * @size: size of the array
 *
 * Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	long unsigned int i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i -1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
