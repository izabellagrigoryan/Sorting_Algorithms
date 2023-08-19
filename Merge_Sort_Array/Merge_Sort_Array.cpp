// Merge_Sort_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Array.h"
template <typename T>

void merge_sort(Array<T>& array)
{
    int size = array.getsize();
    if (size > 1)
    {
        int mid = size / 2;
        Array<T> left(mid);
        Array<T> right(size - mid);

        for (int i = 0; i < mid; i++)
        {
            left[i] = array[i];
        }
        for (int i = mid; i < size; i++)
        {
            right[i - mid] = array[i];
        }

        merge_sort(left);
        merge_sort(right);

        int i = 0, j = 0, k = 0;

        while (i < left.getsize() && j < right.getsize())
        {
            if (left[i] <= right[j])
            {
                array[k] = left[i];
                i++;
            }
            else
            {
                array[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.getsize())
        {
            array[k] = left[i];
            i++;
            k++;
        }

        while (j < right.getsize())
        {
            array[k] = right[j];
            j++;
            k++;
        }
    }
}


int main()
{
    Array<int> m_array(10);

    m_array.print_array();
    merge_sort(m_array);

    std::cout << "Sorted array is: " << std::endl;

    m_array.print_array();

    return 0;
}

