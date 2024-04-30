#include "sort.h"
/**
 * bubble_sort - sort the array using bubble sort
 *
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	int temp;
	size_t i, j;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
}