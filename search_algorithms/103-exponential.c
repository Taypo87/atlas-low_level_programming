#include "search_algos.h"

static int binarySearch(int arr[], int left, int right, int target)
{

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
	return (binarySearch(array, bound/2, (((bound + 1) < (int)size) ? (bound + 1) : (int)size), value));
}
