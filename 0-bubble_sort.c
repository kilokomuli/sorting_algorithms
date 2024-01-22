#include "sort.h"

/**
 * swap_int - swapss two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;

		for (i = 0; i < len  - i - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_int(array + i, array + i + 1);

				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
