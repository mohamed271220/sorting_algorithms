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
	print_array((const int *)array, size);
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
int i, j, pivot = array[high];

for (i = j = low; j < high; j++)
{
if (array[j] < pivot)
{
swap(array, size, &array[j], &array[i++]);
}
}
swap(array, size, &array[i], &array[high]);
return (i);
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

