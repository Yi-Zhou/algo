#include <stdio.h>
#include "mergeSort.h"
#include "../tools.h"

int main() {

    int arr[10] = {9,3,7,6,5,8,1,2,4,0};
    int arr_ascend[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr_descend[10] = {9,8,7,6,5,4,3,2,1,0};
    int arr_concave[10] = {9,8,7,6,5,0,1,2,3,4};
    int arr_cross[10] = {1,3,5,7,9,0,2,4,6,8};

    printf("Before sorting: ");
    print_arr(arr, sizeof(arr) / sizeof(arr[0]));
    mergesort_nonrecursive(arr, sizeof(arr) / sizeof(arr[0]));
    printf("After sorting: ");
    print_arr(arr, sizeof(arr) / sizeof(arr[0]));

    printf("Before sorting: ");
    print_arr(arr_ascend, sizeof(arr_ascend) / sizeof(arr_ascend[0]));
    mergesort_nonrecursive(arr_ascend, sizeof(arr_ascend) / sizeof(arr_ascend[0]));
    printf("After sorting: ");
    print_arr(arr_ascend, sizeof(arr_ascend) / sizeof(arr_ascend[0]));

    printf("Before sorting: ");
    print_arr(arr_descend, sizeof(arr_descend) / sizeof(arr_descend[0]));
    mergesort_nonrecursive(arr_descend, sizeof(arr_descend) / sizeof(arr_descend[0]));
    printf("After sorting: ");
    print_arr(arr_descend, sizeof(arr_descend) / sizeof(arr_descend[0]));

    printf("Before sorting: ");
    print_arr(arr_concave, sizeof(arr_concave) / sizeof(arr_concave[0]));
    mergesort_nonrecursive(arr_concave, sizeof(arr_concave) / sizeof(arr_concave[0]));
    printf("After sorting: ");
    print_arr(arr_concave, sizeof(arr_concave) / sizeof(arr_concave[0]));

    printf("Before sorting: ");
    print_arr(arr_cross, sizeof(arr_cross) / sizeof(arr_cross[0]));
    mergesort_nonrecursive(arr_cross, sizeof(arr_cross) / sizeof(arr_cross[0]));
    printf("After sorting: ");
    print_arr(arr_cross, sizeof(arr_cross) / sizeof(arr_cross[0]));

    return 0;
}