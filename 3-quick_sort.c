#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Array to be sorted
 * @low: starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in array
 * Return: Partition index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; ++j)
	{
		if (array[j] <= pivot)
		{
			++i;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort
 * @low: Stating index of the partition
 * @array: Array to be sorted
 * @high: Ending index Of the partition
 * @size: Number of elements in array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, partition - 1, size);
		quick_sort_recursive(array, partition + 1, high, size);
	}
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

	quick_sort_recursive(array, 0, size - 1, size);
}
