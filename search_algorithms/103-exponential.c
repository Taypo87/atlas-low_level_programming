#include "search_algos.h"

static int binary_search(int array[], int left, int right, int target)
{
	int i = left, m, upper_limit = right;

	while (left <= right && i < upper_limit)
	{
        m = left + (right - left) / 2;
		printf("Searching in array: %d", array[i++]);
		while (i <= right && i < upper_limit)
		{
			printf(", %d", array[i]);
			++i;
		}
		printf("\n");
		
        if (array[m] == target)
		{
			return (m);
		}
        if (array[m] < target)
            left = m + 1;
        else
            right = m - 1;
		i = left - 1;
    }
	if (array[left] == target)
		return (left);
    return (-1);
}

int exponential_search(int *array, size_t size, int value)
{
	int bound = 1, rebound = 0;

	if (!size)
		return (-1);
	
	while (bound < (int)size && array[bound] < value)
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		rebound = bound;
		bound *= 2;
	}
	printf("Value found between indexes [%d] and [%d]\n",
		 rebound, (bound < (int)size ? bound : (int)size - 1));
	return (binary_search(array, rebound,
		 (((bound) < (int)size) ? (bound) : (int)size), value));
}
