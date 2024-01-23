#include "sort.h"

/**
 * swap_ints - swaps two integers in array
 * @a: first integer to be swapped
 * @b: second integer to be swappeed
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - Turn a birnary to acomplete binary heap
 * @array: array to be heapified
 * @size: Number of elements in the array
 * @root: Index of the root of the heap
 */
void heapify(int *array, size_t size, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		swap_ints(array + root, array + largest);
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i);
	for (i = size - 1; i > 0; i--)
	{
		/** Move current root to the end */
		swap_ints(array, array + i);
		print_array(array, size);
		/* Call max heapify on the reduced heap */
		heapify(array, i, 0);
	}
}
