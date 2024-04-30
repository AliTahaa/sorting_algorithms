#include "sort.h"

/**
 * lomuto_partition - partition of the array
 * @array: array of integers to be sorted
 * @low: index in array that begins partition
 * @high: index in array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}

/**
 * quicksort - sorts array of integers by separating into two partitions
 * @array: array of integers to be sorted
 * @low: index in array that begins partition
 * @high: index in array that ends partition
 * @size: amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int a;

	if (low < high)
	{
		a = lomuto_partition(array, low, high, size);
		quicksort(array, low, a - 1, size);
		quicksort(array, a + 1, high, size);
	}
}

/**
 * quick_sort - sorts the array using a quicksort
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
