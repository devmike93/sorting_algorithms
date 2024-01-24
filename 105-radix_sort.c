#include "sort.h"

/**
 * getMax - Get the maximum element from an array.
 * @array: The array.
 * @size: The number of elements in the array.
 *
 * Return: The maximum element.
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort - Perform counting sort on the specified digit.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 * @exp: The exponent that represents the current digit's place value.
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output, count[10] = {0}, j;
	size_t i;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * the Radix Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}
