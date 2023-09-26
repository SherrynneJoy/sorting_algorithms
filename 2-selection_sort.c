#include <stdio.h>
#include "sort.h"
/**
 * selection_sort - sorts an array starting with the minimum value
 * @array: array of integers being sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				temp = array[min];
				/*i is the minimum value so we swap*/
				array[min] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
