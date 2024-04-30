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
if (*a != *b)
{
*a = *a + *b;
*b = *a - *b;
*a = *a - *b;
print_array((const int *)array, size);
}
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
	int pivot, i, j, temp;

	int mid = low + (high - low) / 2;

	if (array[low] > array[mid])
		swap(array, size, &array[low], &array[mid]);
	if (array[low] > array[high])
		swap(array, size, &array[low], &array[high]);
	if (array[mid] > array[high])
		swap(array, size, &array[mid], &array[high]);

	swap(array, size, &array[mid], &array[high]);

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, size, &array[i], &array[j]);
		}
	}
	swap(array, size, &array[i + 1], &array[high]);
	return (i + 1);
}


/**
* quicksort - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
* @low: low index
* @high: high index
*/

void quicksort(int *array, size_t size, int low, int high)
{
if (low < high)
{
size_t pi = partition(array, size, low, high);

quicksort(array, size, low, pi - 1);
quicksort(array, size, pi + 1, high);
}
}




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
	quicksort(array, size, 0, size - 1);
}

