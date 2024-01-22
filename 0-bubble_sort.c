#include "sort.h"

/**
 * bubble_sort - sorts an integer array using the Bubble Sort algorithm.
 * @array: an array of integers to be sorted.
 * @size: is the number of elements in the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = 0, m;
	int temp;
	int swapped = 0;

	if (!array || size < 2)
		return;

	while (n < size - 1)
	{
		for (m = 0; m < size - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				temp = array[m];
				array[m] = array[m + 1];
				array[m + 1] = temp;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
		n++;
	}
}
