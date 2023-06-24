#include "sort.h"

/**
 * shell_sort - Sort array of ints using Shell sort algorithm
 *              with Knuth sequence
 *
 * @array: array of ints to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int tmp;

    if (!array || size < 2)
        return;

    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap >= 1)
    {
        for (i = gap; i < size; i++)
        {
            tmp = array[i];
            for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
                array[j] = array[j - gap];
            array[j] = tmp;
        }
        gap = (gap - 1) / 3;
        print_array(array, size);
    }
}
