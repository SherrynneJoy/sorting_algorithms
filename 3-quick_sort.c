#include "sort.h"

void swap_num(int *a, int *b);
int lomuto_partition(int *array, size_t size, int small, int big);
void q_sort(int *array, size_t size, int small, int big);
void quick_sort(int *array, size_t size);

/**
 * swap_num - swaps numbers
 * @a: first number
 * @b: second number
 */
void swap_num(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - a means of quick sort
 * @array: array to be sorted
 * @size: size of the array
 * @big: big number
 * @small: small number
 * Return: 0 when successful
 */
int lomuto_partition(int *array, size_t size, int small, int big)
{
	int *pivot, up, down;

	pivot = array + big;
	for (up = down =small; down < big; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_num(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivot)
	{
		swap_num(array + up, pivot);
		print_array(array, size);
	}
	return (up);
}
/**
 * q_sort - helps the quick sort function
 * @array: array to be sorted
 * @size: size of the array
 * @big: an integer
 * @small: an integer
 */
void q_sort(int *array, size_t size, int small, int big)
{
	int index = 0;

	if (big - small > 0)
	{
		index = lomuto_partition(array, size, small, big);
		q_sort(array, size, small, index - 1);
		q_sort(array, size, index + 1, big);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;
	q_sort(array, size, 0, size - 1);
}
