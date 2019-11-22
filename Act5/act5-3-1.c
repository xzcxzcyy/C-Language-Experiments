/*
 * 整数的位模式
 */

#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    char bit_pattern[33];
    bit_pattern[32] = '\0';
    int p;
    for (p = 31; p >= 0; --p)
    {
        bit_pattern[p] = (x & 1) + '0';
        x >>= 1;
    }
    printf("%s", bit_pattern);
    return 0;
}
