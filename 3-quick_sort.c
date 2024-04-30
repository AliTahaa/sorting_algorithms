#include "sort.h"
/**
 * swap - swap of two elements
 *
 * @array: array
 * @a: array element
 * @b: array element
 * Return: void
 */
void swap(int *array, ssize_t a, ssize_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
/**
 * lomuto_partition - partitions the array
 *
 * @array: array
 * @low: first array element
 * @high: last array element
 * @size: size array
 * Return: position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t curr = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[curr] != array[j])
			{
				swap(array, curr, j);
				print_array(array, size);
			}
			curr++;
		}
	}
	if (array[curr] != array[high])
	{
		swap(array, curr, high);
		print_array(array, size);
	}
	return (curr);
}
/**
 * quicksort - sort using qucksort algorithm
 *
 * @array: array
 * @fr: first array element
 * @la: last array element
 * @size: array size
 * Return: void
 */
void quicksort(int *array, ssize_t fr, ssize_t la, int size)
{
	ssize_t position = 0;

	if (fr < la)
	{
		position = lomuto_partition(array, fr, la, size);

		quicksort(array, fr, position - 1, size);
		quicksort(array, position + 1, la, size);
	}
}
/**
 * quick_sort - main sort using quicksort
 *
 * @array: array
 * @size: array size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, 0, size - 1, size);
}
