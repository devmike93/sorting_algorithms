#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array.
 *
 * @array: The original array.
 * @left: The left subarray.
 * @l_size: The size of the left subarray.
 * @right: The right subarray.
 * @r_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t l_size, int *right, size_t r_size)
{
	size_t i = 0, j = 0, k = 0, index;
	int *result;

	result = malloc(sizeof(int) * (l_size + r_size));
	if (result == NULL)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, l_size);
	printf("[right]: ");
	print_array(array + l_size, r_size);

	while (i < l_size && j < r_size)
	{ /* Merge the left and right subarrays into the original array.*/
		if (left[i] <= right[j])
			result[k] = left[i++];
		else
			result[k] = right[j++];
		k++;
	}

	while (i < l_size)
	{ /* Copy any remaining elements from the left subarray */
		result[k++] = left[i];
		i++;
	}

	while (j < r_size)
	{ /* Copy any remaining elements from the right subarray */
		result[k++] = right[j];
		j++;
	}

	for (index = 0; index < l_size + r_size; index++)
		array[index] = result[index];

	printf("[Done]: ");
	print_array(array, k);
	free(result);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t mid, left_size, right_size;

	if (array == NULL || size < 2)
		return;

	if (size > 1)
	{
		mid = size / 2;
		left = array;
		right = array + mid;
		left_size = mid;
		right_size = size - mid;

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		merge(array, left, left_size, right, right_size);
	}
}
