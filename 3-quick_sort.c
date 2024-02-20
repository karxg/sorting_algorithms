#include "sort.h"


/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: Pointer to the array to be sorted.
* @size: Number of elements in the array.
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}


/**
* partition - Partitions the array into two parts based on the pivot.
* @array: Pointer to the array.
* @low: Index of the lower bound.
* @high: Index of the higher bound.
* @size: Size of the array.
* Return: Index of the pivot element.
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int temp = 0;
	int j = low;

	for (; j < high; j++)

	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quick_sort_recursive - Recursively sorts a subarray of
* integers using the Quick sort algorithm.
* @array: Pointer to the array to be sorted.
* @low: Index of the lower bound of the subarray.
* @high: Index of the higher bound of the subarray.
* @size: Size of the array.
* Return: void
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}
