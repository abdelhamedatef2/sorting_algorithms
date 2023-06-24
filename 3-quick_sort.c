#include "sort.h"

/**
 * swap - Swaps two ints in array
 * @a: First int
 * @b: Second int
 *
 * Return: VOID
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Order subarray , places pivot
 * @array: Array to be sort
 * @size: Size of array
 * @low: first index of subarray
 * @high: last index of subarray
 *
 * Return: Index of pivot
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
    int i = low - 1, j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < array[high])
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (i + 1 != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quicksort - Sort array of ints in ascending order using quicksort
 * algorithm
 * @array: Array to sort
 * @size: Size of array
 * @low: first index of subarray
 * @high: last index of subarray
 *
 * Return: VOID
 */
void quicksort(int *array, size_t size, int low, int high)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = lomuto_partition(array, size, low, high);
        quicksort(array, size, low, pivot_index - 1);
        quicksort(array, size, pivot_index + 1, high);
    }
}

/**
 * quick_sort - Sort array of ints in ascending order using quicksort
 * algorithm
 * @array: array to be sorted
 * @size: array size
 *
 * Return: VOID
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quicksort(array, size, 0, size - 1);
}
