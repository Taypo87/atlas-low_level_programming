#include "search_algos.h"

/**
 * binary_search - binary search algorithm
 * @array: array to be searched
 * @left: the left boundry being searched
 * @right: the right boundry being searched
 * @target: the target value
 * Return: the indice where the target was found, else -1
*/
static int binary_search(int array[], int left, int right, int target)
{
	int i = 0, m;

	while (left <= right)
	{
		m = (left + (right - left) / 2);
		i = left;
		printf("Searching in array: %d", array[i++]);
		while (i <= right)
		{
			printf(", %d", array[i++]);
		}
		printf("\n");
		if (array[m] == target)
			return (m);
		if (array[m] < target)
			left = m + 1;
		else
			right = m - 1;
	}
	return (-1);
}
/**
 * exponential_search - exponential search algroithm
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the target value
*/
int exponential_search(int *array, size_t size, int value)
{
	int bound = 1, rebound = 0;

	if (!size)
		return (-1);
	
	while ((bound < (int)size - 1) && (array[bound] < value))
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		rebound = bound;
		bound *= 2;
	}
	if (bound > (int)size - 1)
		bound = (int)size - 1;
	printf("Value found between indexes [%d] and [%d]\n",
		rebound, bound);
	return (binary_search(array, rebound, bound, value));
}
