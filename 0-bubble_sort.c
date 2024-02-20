#include "sort.h"
#include <stdio.h>

/**
* bubble_sort - sorts an array of integers in ascending order
* using the Bubble sort algorithm
*
* @array: pointer to the array to be sorted
* @size: size of the array
*
* Return: Nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	int isSorted = 0;

	if (!array || size == 0)
		return;

	while (!isSorted)
	{
		isSorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				isSorted = 0;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

