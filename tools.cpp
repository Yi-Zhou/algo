#include <stdio.h>
#include "tools.h"

int print_arr(int* arr, const size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int print_matrix(int** m, const size_t row, const size_t col)
{
    for (size_t i = 0; i < row; ++i)
    {
        print_arr(m[i], col);
    }
    return 0;
}