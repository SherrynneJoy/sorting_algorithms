#include "sort.h"
#include <stddef.h>

/**
 * swap_int - swaps integers
 * @x: an integer pointer
 * @y: pointer to an int
 * Return: nothing
 */
void swap_int(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to array
 * @size: an integer
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;

	for (i = 0; i < size - 1; i++)
	{
		int swap = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(&array[j], &array[j + 1]);
				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
