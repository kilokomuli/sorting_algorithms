#include "sort.h"
int get_max(int *array, int size);
void countingSort(int *array, size_t size, int sig, int *exp);
void radix_sort(int *array, size_t size);

/**
 * get_max - get the maximum value in the array
 * @array: Array to find the maximum value in
 * @size: Number of elements in the array
 *
 * Return: the maximum value in array
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort -  Perform counting sort on the array based on the
 * signficant digit
 * @array: Array to be sorted
 * @size: Number of elements in the array
 * @sig: Sirginificant digit to sort
 * @exp: significant digit to consider
 */

void countingSort(int *array, size_t size, int sig, int *exp)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		exp[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}
	for (i = 0; i < size; ++i)
		array[i] = exp[i];
}
/**
 * radix_sort - sorts an array of inttegers in ascending order using the ar
 * the Radix sort algorithm
 * @array: the array to be sorted
 * @size: Number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *exp;

	if (array == NULL || size < 2)
		return;

	exp = malloc(sizeof(int) * size);
	if (exp == NULL)
		return;

	max = get_max(array, size);

	for (sig = 1; max / sig > 0; sig *= 10)
	{
		countingSort(array, size, sig, exp);
		print_array(array, size);
	}
	free(exp);
}
