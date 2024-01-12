#include "search_algos.h"

static int binary_search(int arr[], int left, int right, int target)
{
	while (left <= right)
	{
        int m = left + (right - left) / 2;
        if (arr[m] == target)
            return (m);
 
        if (arr[m] < target)
            left = m + 1;
        else
            right = m - 1;
    }
    return (-1);
}

int exponential_search(int *array, size_t size, int value)
{
	int bound = 1;

	if (!size)
		return (-1);
	
	while (bound < (int)size && array[bound] < value)
	{
		bound *= 2;
	}
	return (binary_search(array, bound/2, (((bound + 1) < (int)size) ? (bound + 1) : (int)size), value));
}
