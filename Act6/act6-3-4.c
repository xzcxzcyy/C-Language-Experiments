/*
 * 命令行参数排序
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int less(const void *x, const void *y);
int more(const void *x, const void *y);

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
    {
        puts("Number of parameter(s) error!");
        return -1;
    }

    int (*funcp)(const void *, const void *);
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
    qsort(arr, n, sizeof(int), funcp);

    for (j = 0; j < n; ++j)
    {
        printf("%d ", arr[j]);
    }
}

int less(const void *x, const void *y)
{
    int a = *(int *) x;
    int b = *(int *) y;
    return a - b;
}

int more(const void *x, const void *y)
{
    int a = *(int *) x;
    int b = *(int *) y;
    return b - a;
}
