/*
 * 消除类游戏
 */

#include <stdio.h>

#define MAXN 100

int main()
{
    static int data[MAXN][MAXN];
    static int deleted[MAXN][MAXN] = {{0}};
    int n, m;
    printf("Please input the number of lines and columns:\n");
    scanf("%d %d", &n, &m);
    printf("Please input the map\n");
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            scanf("%d", &data[i][j]);
        }
    }

    /*
     * temp: previous number
     * state: 1 for temp occurred once;
     *        2 for temp occurred twice;
     *        3 for begin to tag;
     */
    int temp;
    int state;
    for (i = 0; i < n; ++i)
    {
        temp = data[i][0];
        state = 1;
        for (j = 1; j < m; ++j)
        {
            switch (state)
            {
                case 1:
                    if (temp == data[i][j])
                    {
                        state = 2;
                    } else
                    {
                        temp = data[i][j];
                    }
                    break;

                case 2:
                    if (temp == data[i][j])
                    {
                        state = 3;
                        deleted[i][j - 2] =
                        deleted[i][j - 1] = deleted[i][j] = 1;
                    } else
                    {
                        temp = data[i][j];
                        state = 1;
                    }
                    break;

                case 3:
                    if (temp == data[i][j])
                    {
                        deleted[i][j] = 1;
                    } else
                    {
                        temp = data[i][j];
                        state = 1;
                    }
                    break;
            }
        }
    }

    for (j = 0; j < m; ++j)
    {
        temp = data[0][j];
        state = 1;
        for (i = 1; i < n; ++i)
        {
            switch (state)
            {
                case 1:
                    if (temp == data[i][j])
                    {
                        state = 2;
                    } else
                    {
                        temp = data[i][j];
                    }
                    break;

                case 2:
                    if (temp == data[i][j])
                    {
                        state = 3;
                        deleted[i - 2][j] =
                        deleted[i - 1][j] = deleted[i][j] = 1;
                    } else
                    {
                        temp = data[i][j];
                        state = 1;
                    }
                    break;

                case 3:
                    if (temp == data[i][j])
                    {
                        deleted[i][j] = 1;
                    } else
                    {
                        temp = data[i][j];
                        state = 1;
                    }
                    break;
            }
        }
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (deleted[i][j])
            {
                printf("%4d", 0);
            } else
            {
                printf("%4d", data[i][j]);
            }
        }
        putchar('\n');
    }
    return 0;
}
