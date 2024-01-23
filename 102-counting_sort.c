#include "sort.h"
/**
 * find_max - Finds the maximum value in an array
 * @array: the array to search
 * @size: Number of elements in array
 * Return: the maximum value in array
 */
int find_max(int *array, size_t size)
{
	int max;
	size_t i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, max, i;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = find_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sort[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];

	free(sort);
	free(count);
}
