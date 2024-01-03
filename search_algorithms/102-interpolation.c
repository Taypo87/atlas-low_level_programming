#include "search_algos.h"


/**
 * interpolation_search - searches an array for a given value
 * @array: the array
 * @size: size of the array
 * @value: the value being searched for
*/
int interpolation_search(int *array, size_t size, int value)
{
	int l = 0, m, h;

	if (!array || size == 0)
	{
		return (-1);
	}
	h = (int)size - 1;
	m = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
	if (m > array[h] || m < array[l])
	{
		printf("Value checked array[%d] is out of range\n", m);
		return (-1);
	}
	while ((array[h] != array[l]) && (value >= array[l]) && (value <= array[h]))
	{
		m = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
		printf("Value checked array[%d] = [%d]\n", m, array[m]);
		if (array[m] < value)
			l = m + 1;
		else if (array[m] > value)
			h = m - 1;
		else
			return (m);
	}
	
	if (value == array[l])
		return (l);
	else 
		return (-1);
}
