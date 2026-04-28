#include "sort.h"

/**
 * swap_items - Swaps two integers in an array
 * @array: The array containing the items
 * @size: The size of the array
 * @a: Pointer to the first item
 * @b: Pointer to the second item
 */
void swap_items(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: The array to partition
 * @size: The size of the array
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The final partition index
 */
size_t lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap_items(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap_items(array, size, &array[i], &array[high]);

	return (i);
}

/**
 * quick_sort_recursive - Recursive helper for quick_sort
 * @array: The array to sort
 * @size: The size of the array
 * @low: The starting index
 * @high: The ending index
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		size_t p_idx = lomuto_partition(array, size, low, high);

		quick_sort_recursive(array, size, low, p_idx - 1);
		quick_sort_recursive(array, size, p_idx + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
