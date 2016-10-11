#include "../tools.h"
#include "stdio.h"
#include <string>
#include <cstdlib>

int palindrome_recursive(std::string str, int i, int j)
{    
    int tmp1, tmp2;
    if (i == j) return 1;
    if (i > j) return 0;

    if (str[i] == str[j]) return palindrome_recursive(str, i+1, j-1)+2;

    tmp1 = palindrome_recursive(str, i+1, j), tmp2 = palindrome_recursive(str, i, j-1);

    return tmp1 > tmp2? tmp1: tmp2;

}

int palindrome_dynamic(std::string str, int i, int j)
{
    int** arr = (int**) malloc(10*sizeof(int*));

    int a, b;
    for (a = 0; a < 10; ++a) 
    {
        arr[a] = (int*) malloc(10*sizeof(int));
        for (b = 0; b < 10; ++b)
            arr[a][b] = 0;
    }

    for (b = i; b <= j; ++b)
    {
        for (a = j; a >= i; --a)
        {
            if (a > b) arr[a][b] = 0;
            else if (a == b) arr[a][b] = 1;
            else if (str[a] == str[b]) arr[a][b] = arr[a+1][b-1]+2;
            else arr[a][b] = arr[a+1][b] > arr[a][b-1]? arr[a+1][b]: arr[a][b-1];
        }
    }
    return arr[i][j];
}

int main() 
{
    std::string str = "BBABCBCAB";
    printf("answer recursive: %d\n", palindrome_recursive(str, 0, 8));
    printf("answer dynamic: %d\n", palindrome_dynamic(str, 0, 8));

    return 0;
}