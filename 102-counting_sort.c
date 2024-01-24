#include "sort.h"

/**
 * count_max - finds the maximum value in the input array.
 * @array: the array to be sorted.
 * @size: the number of elements in the array.
 *
 * Return: the maximum value in the array.
 */
int count_max(int *array, size_t size)
{
	int max_value = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	return (max_value);
}

/**
 * reconstruct_sorted_array - reconstructs the sorted array.
 *
 * @array: the original array to be sorted.
 * @size: the number of elements in the array.
 * @counting_array: the counting array with accumulated counts.
 */
void reconstruct_sorted_array(int *array, size_t size, int *counting_array)
{
	int *output_array;
	size_t i;

	/* Reconstruct the sorted array from the counting array. */
	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
	}

	/* Copy the sorted elements back to the original array*/
	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(output_array);
	free(counting_array);
}

/**
 * counting_sort - sorts an array of integers in ascending order using the
 *				 Counting Sort algorithm.
 * @array: is the array to be sorted.
 * @size: is the number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array;
	size_t i, max_value;

	if (array == NULL || size < 2)
		return;

	/* Create the counting array of size (max_value + 1). */
	max_value = count_max(array, size);
	counting_array = malloc(sizeof(int) * (max_value + 1));
	if (counting_array == NULL)
		return;

	/* Initialize the counting array elements to 0. */
	for (i = 0; i <= max_value; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each element in the input array. */
	for (i = 0; i < size; i++)
		counting_array[array[i]] += 1;

	/* Accumulate the counts in the counting array. */
	for (i = 0; i < max_value; i++)
		counting_array[i + 1] += counting_array[i];

	/* Print the counting array. */
	print_array(counting_array, max_value + 1);

	/* Reconstruct the sorted array from the counting array. */
	reconstruct_sorted_array(array, size, counting_array);
}
