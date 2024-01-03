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
	int pos;

	h = (int)size - 1;
	if (array[h] < value)
		return (-1);

	while ((array[h] != array[l]) && (value >= array[l]) && (value <=array[h]))
	{
		m = l +(value - array[l]) * (h - l) / array[h] - array[l];
		pos = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
		printf("Value checked array[%d] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		if (array[m] < value)
			l = m + 1;
		else if (value < array[m])
			h = m - 1;
		else
			return (m);
	}
	
	return (h);
}
