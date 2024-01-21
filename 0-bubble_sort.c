#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swap;

	for (i = 0; i < size - 1; ++i)
	{
		swap = 0;

		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap = 1;
				
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
