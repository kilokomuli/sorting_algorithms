#include "sort.h"

/**
 * swap_int - swaps two integrs in an array.
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort- sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: Array to be sorted
 * @size: Number of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		min = array + 1;

		for (j = i + 1; j < size; ++j)
			min = (array[j] < *min) ? (array + j) : min;
		if ((array + i) != min)
		{
			swap_int(array + i, min);
			print_array(array, size);
		}
	}
}
