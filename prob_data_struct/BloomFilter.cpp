#include <stdio.h>
#include <math.h>
#include "../tools.h"

#define M 23


int rank(char x)
{
    return x-96;
}

int hash(char S [], int j)
{
    int i = 0;
    int mul = (int) pow(3, j);
    int sum = 0;
    // printf("string: %s\n", S);
    while (S[i] != 0)
    {
        mul *= 3;
        sum += rank(S[i])*mul;
        i++;
    }
    // printf("pos: %d\n", sum % M);
    return sum % M;
}

int main() 
{
    // Hj(string S) = SIGMA(rank(S[i])*3^(j+i)) mod m
    // where rank('a') = 1, rank('b') = 2, ..., rank('z') = 26
    // j = 1, 2, two hash functions H1 and H2
    // m = 23

    char S [100];
    char c;
    int len = 0;
    int BloomFilter [23] = {0};

    while (1)
    {
        do
        {
            scanf("%c", &c);
            S[len++] = c;
        }
        while (c != '\n' && c != ' ' );

        S[--len] = 0;
        if (len == 0) break;

        BloomFilter[hash(S, 1)] = 1;
        BloomFilter[hash(S, 2)] = 1;

        print_arr(BloomFilter, 23);

        len = 0;
    }
}

