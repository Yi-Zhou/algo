#include "../tools.h"
#include <cstdio>
#include <string>
#include <cstdlib>

/**
Problem:
    A palindrome is a nonempty string covering some alphabets that read the same forward
    and backward​. Examples of palindromes include:
    - all strings of length 1,
    - "civic",
    - "racecar"
    - "aibohphobia.
    Given an input string X, the Longest Palindrome Subsequence Problem is to find the
    length of the longest palindrome L that is a subsequence of string X. For example, give the
    input X="BBABCBCAB", the output should be 7 as "BABCBAB" is the longest palindrome
    subsequence.
*/

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
    int** L = (int**) malloc((j+1)*sizeof(int*));

    int a, b;
    for (a = 0; a < 10; ++a) L[a] = (int*) malloc((j+1)*sizeof(int));

    for (b = i; b <= j; ++b)
    {
        for (a = j; a >= i; --a)
        {
            if (a > b) L[a][b] = 0;
            else if (a == b) L[a][b] = 1;
            else if (str[a] == str[b]) L[a][b] = L[a+1][b-1]+2;
            else L[a][b] = L[a+1][b] > L[a][b-1]? L[a+1][b]: L[a][b-1];
        }
    }
    return L[i][j];
}

int main() 
{
    std::string str = "BBABCBCAB";
    printf("answer recursive: %d\n", palindrome_recursive(str, 0, 8));
    printf("answer dynamic: %d\n", palindrome_dynamic(str, 0, 8));

    return 0;
}