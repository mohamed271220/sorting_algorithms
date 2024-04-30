#include "sort.h"


/**
* quick_sort - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}


/**
* quick_sort_recursive - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
* @low: low index
* @high: high index
*/

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
* partition - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
* @low: low index
* @high: high index
* Return: pivot index
*/


int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j;

	int tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}
