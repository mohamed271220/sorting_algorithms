#include "sort.h"


/**
* swap - swaps two integers
* @array: array to swap
* @size: size of the array
* @a: first integer
* @b: second integer
* return: void
*/

void swap(int *array, size_t size, int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}


/**
* partition - partitions the array
* @array: array to partition
* @size: size of the array
* @low: low index
* @high: high index
* Return: index of the pivot
*/
size_t partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];

	int i = low - 1;

	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, size, &array[i], &array[j]);
		}
	}
	swap(array, size, &array[i + 1], &array[high]);
	return (i + 1);
}


/**
* quick_sort - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	int low = 0;

	int high = size - 1;

	if (array == NULL || !size)
		return;
	if (low < high)
	{
		size_t pi = partition(array, size, low, high);

		quick_sort(array, pi);
		quick_sort(array + pi + 1, size - pi - 1);
	}
}
