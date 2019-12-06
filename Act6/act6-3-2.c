/*
 * 序列去重
 */

#include <stdio.h>

#define N 500

int RemoveSame(int *a, int n);

int main()
{
    static int arr[N];
    int n;
    scanf("%d", &n);
    int *p;
    for (p = arr; p < arr + n; ++p)
    {
        scanf("%d", p);
    }

    int number = RemoveSame(arr, n);
    for (p = arr; p < arr + number; ++p)
    {
        printf("%d ", *p);
    }
    return 0;
}

int RemoveSame(int *a, int n)
{
    int previous = *a;
    int *r;
    int *w = a + 1;
    for (r = a + 1; r < a + n; ++r)
    {
        if (*r == previous)
        {
            continue;
        }
        previous = *r;
        *w = *r;
        ++w;
    }
    return w - a;
}
