/*
 * 高精度乘法
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int *mMultiply(const int *x, const int *y);
int *read();

int main()
{
    int *a = read();
    int *b = read();
    int *res = mMultiply(a, b);
    for (int i = res[0]; i >= 1; --i)
    {
        putchar('0' + res[i]);
    }
    putchar('\n');
    return 0;
}

// 输入数据是从低位开始存的，且没有前导零
int *mMultiply(const int *x, const int *y)
{
    const int base = 10;
    int lx = x[0], ly = y[0];
    int buff = 0;
    int *res = (int *) malloc((lx + ly + 1) * sizeof(int));
    memset(res, 0, (lx + ly + 1) * sizeof(int));
    for (int i = 1; i <= lx; ++i)
    {
        for (int j = 1; j <= ly; ++j)
        {
            res[i + j - 1] += x[i] * y[j] + buff;
            buff = res[i + j - 1] / base;
            res[i + j - 1] %= base;
        }
        if (buff)
        {
            res[i + ly] = buff;
            buff = 0;
        }
    }
    if (res[lx + ly])
    {
        res[0] = lx + ly;
    } else
    {
        res[0] = lx + ly - 1;
    }
    return res;
}

int *read()
{
    int end = 1;
    char *x = (char *) malloc(200 * sizeof(char));
    scanf("%s", x);
    int length = strlen(x);
    int *res = (int *) malloc((length + 1) * sizeof(int));
    res[0] = length;
    for (int i = 1; i <= length; ++i)
    {
        res[i] = x[length - i] - '0';
    }
    return res;
}
