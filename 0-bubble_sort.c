#include "sort.h"

/**
 * bubble_sort - sorts an integer array using the Bubble Sort algorithm.
 * @array: an array of integers to be sorted.
 * @size: is the number of elements in the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

			}
		}
		/* Print the array after each pass */
		print_array(array, size);
	}
}
