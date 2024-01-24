#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using Shell Sort
 *              with the Knuth sequence.
 * @array: is the array to be sorted.
 * @size: is the number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t a, b, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		a = gap;

		while (a < size)
		{
			temp = array[a];
			b = a;

			while (b >= gap && array[b - gap] > temp)
			{
				array[b] = array[b - gap];
				b -= gap;
			}

			array[b] = temp;

			a++;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
