#include "sorts.h"

void swap(int *el1, int *el2)
{
    int temp = *el1;
    *el1 = *el2;
    *el2 = temp;
}

void bubble_sort(int *a, size_t length)
{
    for (size_t i = 0; i < length; i++)
        for (size_t j = 0; j < length - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a + j, a + j + 1);
}

void quick_sort(int *a, long begin, long end)
{
    long left = begin, right = end;
    if (left == right)
        return;

    int mid = a[begin];
    while (left <= right)
    {
        while (a[left] < mid) left++;
        while (a[right] > mid) right--;
        if (left <= right)
        {
            swap(a + left, a + right);
            left++, right--;
        }
    }
    if (right > begin)
        quick_sort(a, begin, right);
    if (left < end)
        quick_sort(a, left, end);
}

void insertion_sort(int* a, size_t length) 
{
	for (size_t i = 1; i < length; i++) 
    {
		for (size_t j = i; j > 0 && a[j - 1] > a[j]; j--)
        {
		    swap(a + j - 1, a + j);
		}
	}
}