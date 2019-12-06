/*
 * 最长的串
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

char **findLongest(int n, char **arr, int *length);

int main()
{
    char *arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = (char *) malloc(50 * sizeof(char));
        scanf("%s", arr[i]);
    }
    int maxlength;
    char **tar = findLongest(N, arr, &maxlength);
    printf("length: %d, %s", maxlength, *tar);
    return 0;
}

char **findLongest(int n, char **arr, int *length)
{
    int i;
    char **res = arr;
    int maxlength = strlen(*arr);
    for (i = 1; i < n; ++i)
    {
        if (strlen(arr[i]) > maxlength)
        {
            maxlength = strlen(arr[i]);
            res = arr + i;
        }
    }
    *length = maxlength;
    return res;
}
