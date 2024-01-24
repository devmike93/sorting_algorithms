#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	quick_recur_sort(array, 0, size - 1, size);
}

/**
 * Lomuto - Partitions the array using the Lomuto partition scheme.
 *
 * @array: The array to be partitioned.
 * @low: The index of the low element.
 * @high: The index of the high element.
 * @size: The number of elements in the array.
 *
 * Return: The index of the pivot element after partitioning.
 */
int Lomuto(int *array, int low, int high, size_t size)
{
	int pivot, n, m, tmp;

	pivot = array[high];
	n = low - 1;

	for (m = low; m <= high; m++)
	{
		if (array[m] <= pivot)
		{
			n += 1;
			if (n != m)
			{
				tmp = array[n];
				array[n] = array[m];
				array[m] = tmp;
				print_array(array, size);
			}
		}
	}

	return (n);
}

/**
 * quick_recur_sort - Recursively sorts an array using the
 *                    Quick Sort algorithm.
 * @array: The array to be sorted.
 * @low: The index of the low element.
 * @high: The index of the high element.
 * @size: The number of elements in the array.
 */
void quick_recur_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = Lomuto(array, low, high, size);
		quick_recur_sort(array, low, pivot - 1, size);
		quick_recur_sort(array, pivot + 1, high, size);
	}
}


