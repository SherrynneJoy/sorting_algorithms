#include <stdio.h>
#include "sort.h"
/**
 * sell_sort - sorts an arrayof integers using the knuth's sequence
 * @array: array being sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i , j;
	int val;

	while (interval < size/3)
		interval = interval * 3 + 1;
	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			/*select value to be inserted*/
			val = array[i];
			j = i;
			/*shift elements to the right*/
			while (j > interval - 1 && array[j - interval] >= val)
			{
				array[j] = array[j - interval];
				j = j - interval;
			}
			array[j] = val;
		}
		interval = (interval - 1)/3;
	}
	print_array(array, size);
}
