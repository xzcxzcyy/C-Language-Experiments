/*
 * 走迷宫
 */

#include <stdio.h>

#define MAXN 20

int map[MAXN][MAXN] = {0};

void input(int line, int column);
void print(int line, int column);
int available(int x, int y, int line, int column);
void search(int x, int y, int line, int column);

int main()
{
    printf("Please enter the number of lines and columns:\n");
    fflush(stdout);
    int line, column;
    scanf("%d %d", &line, &column);
    printf("Please input your map; 0 for empty fields and 1 for walls.\n");
    fflush(stdout);
    input(line, column);

    puts("Your Map: ");
    print(line, column);
    putchar('\n');
    puts("Solution(s): ");
    if (available(0, 0, line, column))
    {
        search(0, 0, line, column);
    }
    return 0;
}

void input(int line, int column)
{
    int i, j;
    for (i = 0; i < line; ++i)
    {
        for (j = 0; j < column; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

// 使用 ANSI 转义序列输出色块以绘制地图。
void print(int line, int column)
{
    putchar('\n');
    int i, j;
    for (i = 0; i < line; ++i)
    {
        for (j = 0; j < column; ++j)
        {
            switch (map[i][j])
            {
                case 0:
                    printf("\033[48;2;158;158;158m  \033[0m");
                    break;
                case 1:
                    printf("\033[48;2;66;66;66m  \033[0m");
                    break;
                case 2:
                    printf("\033[48;2;129;199;132m  \033[0m");
                    break;
            }
        }
        putchar('\n');
    }
}

int available(int x, int y, int line, int column)
{
    return x >= 0 && x < line && y >= 0 && y < column && (map[x][y] == 0);
}

void search(int x, int y, int line, int column)
{
    map[x][y] = 2;
    // 如果到终点
    if (x == line - 1 && y == column - 1)
    {
        print(line, column);
        map[x][y] = 0;
        return;
    }
    int i;
    for (i = -1; i <= 1; i += 2)
    {
        if (available(x + i, y, line, column))
        {
            search(x + i, y, line, column);
        }
        if (available(x, y + i, line, column))
        {
            search(x, y + i, line, column);
        }
    }
    map[x][y] = 0;
}
