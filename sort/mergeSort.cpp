#include <stdio.h>
#include "mergeSort.h"
#include "../tools.h"

int mergesort_recursive(int* arr, const size_t len) 
{
    if (len == 1) return 0;

    size_t  n_l = len / 2, n_r = len - n_l,
            i = 0, j = 0, k = 0;
    int arr_l[n_l], arr_r[n_r];


    for (i = 0; i < n_l; ++i) arr_l[i] = arr[i];
    for (i = 0; i < n_r; ++i) arr_r[i] = arr[n_l+i];

    mergesort_recursive(arr_l, n_l);
    mergesort_recursive(arr_r, n_r);

    // merge
    for (i = 0; i < len; ++i)
    {
        if (j < n_l && (k >= n_r || arr_l[j] <= arr_r[k])) arr[i] = arr_l[j++];
        else arr[i] = arr_r[k++];
    }

    return 0;
}

int _copy(int* arr, int* dup_arr, int offset, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        dup_arr[i] = arr[offset + i];
    return 0;
}

int mergesort_nonrecursive(int* arr, const size_t len)
{
    // bottom up
    int size = 1, offset = 0;
    int left = 0, right = left + size;
    int dup_arr [len];
    int i, min;

    for (i = 0; i < len; ++i) dup_arr[i] = 0;
    i = 0;

    while (size < len)
    {
        if (2*size < len) min = 2*size;
        else min = len;

        while (offset + size < len)
        {
            left = 0, right = size;
            _copy(arr, dup_arr, offset, size);

            for (i = 0; i < size * 2; ++i)
            {
                if (left < size && (right >= min || dup_arr[left] <= arr[right + offset]))
                {
                    arr[i + offset] = dup_arr[left];
                    left++;
                }
                else if (right + offset < len && (left >= size || dup_arr[left] > arr[right + offset]))
                {
                    arr[i + offset] = arr[right + offset];
                    right++;
                }
                else break;
            }

            offset += size * 2;
        }
        offset = 0;
        size *= 2;
    }


    return 0;    
}

int mergesort_inplace_nonrecursive_naive(int* arr, const size_t len) 
{

    size_t  mul = 1,
            i, j, k, l, tmp;
    int jvalid, kvalid;

    while (mul < len)
    {
        for (i = 0; i < len; i += 2 * mul)
        {
            // at position 2*i*mul
            j = i, k = i + mul;

            jvalid = j < k;
            kvalid = k < i + 2 * mul && k < len;

            while (jvalid && kvalid)
            {
                if (jvalid && (arr[j] < arr[k] || !kvalid)) j++;
                else 
                {
                    tmp = arr[k];
                    for (l = k++; l > j; --l) arr[l] = arr[l-1]; // shift right
                    arr[j++] = tmp;
                }

                jvalid = j < k;
                kvalid = k < i + 2 * mul && k < len;
            }
        }

        mul *= 2;
    }

    return 0;
}

int _swap(int* arr, size_t i, size_t j) {
    size_t tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;

    return 0;
}

