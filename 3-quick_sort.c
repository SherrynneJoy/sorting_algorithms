#include <stdio.h>
#include "sort.h"
/**
 * swap_val - swaps values a and b
 * @a: first value
 * @b: second value
 */
void swap_val(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - partitions array using pivot
 * @array: array
 * @size: size of array
 * @start: first-most value
 * @end: pivot element
 * Return: int
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, high, low;

	pivot = array + end;
	for (high = low = start; low < end; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap_val(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}
	if (array[high] > *pivot)
	{
		swap_val(array + high, pivot);
		print_array(array, size);
	}
	return (high);
}
/**
 * lomuto_sort - further subdivides the subclasses till single values are left
 * @array: array being sorted
 * @size: size of array
 * @start: value at first index
 * @end:pivot value
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int sub;

	if (end - start > 0)
	{
		sub = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, sub - 1);
		lomuto_sort(array, size, sub + 1, end);
	}
}
/**
 * quick_sort - sorts an array using a pivot element
 * @array: array being sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 1)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
