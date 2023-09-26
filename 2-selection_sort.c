#include "sort.h"

/**
 * swap - swaps two integers
 * @m: first int
 * @n: second int
 */
void swap(int *m, int *n)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
	if (min != i)
	{
		swap(&array[i], &array[min]);
		print_array(array, size);
	}
	}
}
