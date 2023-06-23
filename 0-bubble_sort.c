#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * bubble_sort - sorts an arr in ascending order using bubble sort
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t w, y;
	int temp;

	/**
	 * The outer for loop iterates over the array/ its the passes
	 * w < size - 1, ensures the loop will iterate over the array
	 * until w reaches the 2nd last index. It ensures that during
	 * each iteration for outer loop, the algorithm can compare
	 * each element with its adjacent element and perform the
	 * neccessary swap if the order is incorrect
	 * The inner loop iterates only over unsorted array hence the
	 * y < size - 1 - w
	 */
	if (size < 2)
		return;

	for (w = 0; w < size - 1; w++)
	{
		for (y = 0; y < size - 1 - w; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
