#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending O
 * @array: the array to sought
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t e, f, min_pos;
	size_t temp;
	/*min_pos track the index of the smallest element*/

	if (array == NULL || size < 2)
		return;

	for (e = 0; e < size - 1; e++) /*rep current iteration/pass*/
	{
		min_pos =  e;

		for (f = e + 1; f < size; f++)
		{
			if (array[f] < array[min_pos])
				min_pos = f;
		}

		if (min_pos != e)
		{
			temp = array[e];
			array[e] = array[min_pos];
			array[min_pos] = temp;
			print_array(array, size);
		}
	}
}
