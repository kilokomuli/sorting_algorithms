#include "sort.h"

void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

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
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Array to be sorted
 * @low: starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in array
 * Return: Partition index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int piv = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j <= high - 1; ++j)
	{
		if (array[j] <= piv)
		{
			++i;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;

	print_array(array, size);
	return (i + 1);
}
