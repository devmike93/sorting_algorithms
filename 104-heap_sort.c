#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two integers in an array.
 * @a: a pointer to the first integer.
 * @b: a pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - adjusts the max heap by moving an element down.
 * @array: the array to be sorted.
 * @size: the number of elements in the array.
 * @start: the starting index of the sub-heap.
 * @end: the ending index of the sub-heap.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root, child, swap_index;

	root = start;
	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap_index = root;

		if (array[swap_index] < array[child])
			swap_index = child;
		if (child + 1 <= end && array[swap_index] < array[child + 1])
			swap_index = child + 1;

		if (swap_index != root)
		{
			swap(&array[root], &array[swap_index]);
			print_array(array, size);
			root = swap_index;
		}
		else
			break;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using
 *             the Heap Sort algorithm.
 * @array: the array of integers to be sorted.
 * @size: the number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
