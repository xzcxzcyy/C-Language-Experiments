/*
 * 命令行参数排序
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int less(const int x, const int y);
int more(const int x, const int y);
void mqsort(int *begin, int *end, int (*cmp)(const int x, const int y));
void mswap(int *a, int *b);

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
    {
        puts("Number of parameter(s) error!");
        return -1;
    }

    int (*funcp)(const int, const int);
    int i;
    if (argc == 3)
    {
        if (strcmp("-d", argv[1]) != 0 && strcmp("-d", argv[2]) != 0)
        {
            puts("Parameter error!");
            return -1;
        }
        funcp = more;
        i = strcmp("-d", argv[1]) == 0 ? 2 : 1;
    } else
    {
        funcp = less;
        i = 1;
    }

    char *endPtr = NULL;
    int n = strtol(argv[i], &endPtr, 10);

    if (endPtr == argv[i])
    {
        puts("No number detected");
        return -1;
    }

    int arr[n];
    int j;
    for (j = 0; j < n; ++j)
    {
        scanf("%d", &arr[j]);
    }
    mqsort(arr, arr + n, funcp);

    for (j = 0; j < n; ++j)
    {
        printf("%d ", arr[j]);
    }
}

int less(const int x, const int y)
{
    return x - y;
}

int more(const int x, const int y)
{
    return y - x;
}

void mqsort(int *begin, int *end, int (*cmp)(const int x, const int y))
{
    if (end - begin <= 1)
    {
        return;
    }
    int *i = begin, *j = end - 1;
    int pivot = *(i + (end - begin) / 2);
    while (i <= j)
    {
        while (cmp(*i, pivot) < 0)
        {
            ++i;
        }
        while (cmp(pivot, *j) < 0)
        {
            --j;
        }
        if (i <= j)
        {
            mswap(i, j);
            ++i;
            --j;
        }
    }
    mqsort(begin, j + 1, cmp);
    mqsort(i, end, cmp);
}

void mswap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
