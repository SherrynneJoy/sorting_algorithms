#include "sort.h"

/**
 * swap_ints - swaps integers
 * @x: first int
 * @y: second int
 */
void swap_ints(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j = 0;

	if (array == NULL || size <= 1)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval = interval / 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_ints(array + j, array + (j - interval));
				j = j - interval;
			}
		}
		print_array(array, size);
	}
}
