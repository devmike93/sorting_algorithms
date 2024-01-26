#include "sort.h"

/**
 * merge - merge two subarrays in bitonic order
 * @array: is the array to be sorted
 * @low: start index of the first subarray.
 * @count: is the umber of elements to merge.
 * @dir: sorting direction (1 for UP, 0 for DOWN).
 */
void merge(int *array, size_t low, size_t count, int dir)
{
	size_t mid, i;
	int temp;

	if (count > 1)
	{
		mid = count / 2;

		for (i = low; i < low + mid; i++)
		{
			if ((array[i] > array[i + mid]) == dir)
			{
				temp = array[i];
				array[i] = array[i + mid];
				array[i + mid] = temp;
			}
		}

		merge(array, low, mid, dir);
		merge(array, low + mid, mid, dir);
	}
}

/**
 * bitonic_merge - recursively sort a bitonic sequence.
 * @array: is the array to be sorted.
 * @size: is the number of elements in the array.
 * @low: start index of the sequence.
 * @count: number of elements in the sequence.
 * @dir: sorting direction (1 for UP, 0 for DOWN).
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir)
{
	size_t mid;
	char *str;

	if (count > 1)
	{
		mid = count / 2;

		str = (dir == 1) ? "UP" : "DOWN";
		printf("Merging [%ld/%ld] (%s):\n", count, size, str);
		print_array(array + low, count);

		bitonic_merge(array, size, low, mid, 1);
		bitonic_merge(array, size, low + mid, mid, 0);
		merge(array, low, count, dir);

		printf("Result [%ld/%ld] (%s):\n", count, size, str);
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 *                Bitonic Sort algorithm.
 * @array: is the array to be sorted.
 * @size: is the number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_merge(array, size, 0, size, 1);
}
