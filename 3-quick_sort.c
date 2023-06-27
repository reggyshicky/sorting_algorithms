#include "sort.h"

/**
 * Lomuto_partition - partitions the array in Lomuto way
 * @array: array to sort
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: nothing!
 */
int Lomuto_partition(int *array, int low, int high, size_t size)
{
	int w = 0, x = 0, temp = 0;

	w = low - 1;

	for (x = low; x < high; x++)
	{
		if (array[x] < array[high])
		{
			w++;
			if (w != x)
			{
				temp = array[w];
				array[w] = array[x];
				array[x] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[w + 1])
	{
		temp = array[w + 1];
		array[w + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (w + 1);
}

/**
 * quick_recursion - quick sort function helper
 * @array: array to sort
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: nothing
 */
void quick_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = Lomuto_partition(array, low, high, size);
		quick_recursion(array, low, pivot - 1, size);
		quick_recursion(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - uses Quicksort to sort an array
 * @array: array to sort
 * @size: size of the array to sort
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_recursion(array, 0, (int)size - 1, size);
}
