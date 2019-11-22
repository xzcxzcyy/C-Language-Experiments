/*
 * 约瑟夫问题
 * 代码优化
 */

#include <stdio.h>

#define M 10
#define N 3

int main(void)
{
    int a[M], b[M];
    int is_out[M] = {0}; // 用来标记的数组
    int i, j, k;
    for (i = 0; i < M; ++i)
    {
        a[i] = i + 1;
    }
    for (i = M, j = 0; i > 1; i--)
    {
        for (k = 1; k <= N - 1; k++)
        {
            do
            {
                if (++j > M - 1)
                {
                    j = 0;
                }
            } while (is_out[j]);
        }
        b[M - i] = a[j];
        is_out[j] = 1;
        do
        {
            if (++j > M - 1)
            {
                j = 0;
            }
        } while (is_out[j]);
    }
    for (i = 0; i < M - 1; i++)
    {
        printf("%6d", b[i]);
    }
    printf("%6d", a[j]);
    return 0;
}
