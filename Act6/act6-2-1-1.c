/*
 * 字符串排序函数
 */

// 1st blank: malloc 函数位于头文件 stdlib.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

void strsort(char *s[], int size)
{
    char *temp; // 2nd blank
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (strcmp(s[j], s[j + 1]) > 0) // 3rd blank
            {
                temp = s[j];
                s[j] = s[j + 1]; // 4th blank
                s[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i;
    char *s[N], t[50];
    for (i = 0; i < N; i++)
    {
        gets(t);
        s[i] = malloc(strlen(t) + 1); //TODO: type cast required
        strcpy(s[i], t); // 5th blank
    }
    strsort(s, N);
    for (i = 0; i < N; i++)
    {
        puts(s[i]);
    }
    return 0;
}
