#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the quick sort algorithm
 * @array:  Array to be sorted
 * @size: Number of elements in array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recur(array, size 0, size - 1);
}

/**
 * Quick_sort_recur - Recursive function for Quick sort
 *
