#include <stdio.h>
#include "tools.h"

int print_arr(int* arr, const size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
