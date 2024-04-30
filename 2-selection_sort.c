#include "sort.h"
/**
 * selection_sort - sorts an array of using selection sort
 *
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, f;
	int temp;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = size - 1, f = i + 1; j > i; j--)
		{
			if (array[j] < array[f])
				f = j;
		}
		if (array[i] > array[f])
		{
			temp = array[i];
			array[i] = array[f];
			array[f] = temp;
			print_array(array, size);
		}
	}
}
