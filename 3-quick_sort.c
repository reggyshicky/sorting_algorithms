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
	int i, j, temp, pivot;

	pivot = array[high];
	i = low - 1; /*indicates that initially, no elem 2 the left*/

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
	/**
	 * The array[high] < array[i + 1]), check if the pivot element is
	 * smaller than elem at pos i + 1 (current j)
	 */
}

/**
 * quick_recursion - quick sort function helper
 * @array: array to sort
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: void
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
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_recursion(array, 0, size - 1, size);
}
