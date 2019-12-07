/*
 * 旋转矩阵
 */

#include <stdio.h>

/*
 * 根据几何知识，
 * 坐标 (i, j) 旋转过后为 (line - j, i)
 */

void spin(int *target, const int *source, int line, int column);

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    int tar[m][n];
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    spin(&tar[0][0], &arr[0][0], n, m);
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%d ", tar[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

void spin(int *target, const int *source, int line, int column)
{
    int i, j;
    for (i = 0; i < line; ++i)
    {
        for (j = 0; j < column; ++j)
        {
            *(target + line * (column - 1 - j) + i) = *(source + column * i + j);
        }
    }
}
