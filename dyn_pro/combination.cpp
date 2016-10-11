#include "../tools.h"
#include <cstdio>
#include <cstdlib>

/**
Problem:
    find the value of combination C(n, k);
*/

int C_recursive(int n, int k)
{
    if (k == 0 || n == k) return 1;
    return C_recursive(n-1, k-1) + C_recursive(n-1, k);
}
int C(int n, int k)
{
    int** C = (int**) malloc(n*sizeof(int*));
    int i, j, min;
    
    for (i = 0; i < n; ++i) C[i] = (int*) malloc((k+1)*sizeof(int));
    // n: from 1 to n -> n
    // k: from 0 to k -> k+1

    for (i = 0; i < n; ++i)
    {
        min = i+1 < k? i+2: k+1;
        for (j = 0; j < min; ++j)
        {
            if (j == 0) C[i][j] = 1;
            else if (j == i+1) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }
    return C[--n][k];
}

int main() 
{
    printf("answer recursive: %d\n", C_recursive(5, 2));
    printf("answer dynamic: %d\n", C(5, 2));
}
