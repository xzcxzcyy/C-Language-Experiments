/*
 * 马踏棋盘
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int map[8][8];

int dx[8] = {+2, +1, -1, -2, -2, -1, +1, +2};
int dy[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

void search(int x, int y, int step);
void print();
void mrand();
int check(int x, int y);

int main()
{
    srand((unsigned) time(NULL));
    map[0][0] = 1;
    search(0, 0, 1);
}

void search(int x, int y, int step)
{
    assert(step <= 64);
    if (step == 64)
    {
        print();
        exit(0);
    }
    //mrand();
    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny))
        {
            map[nx][ny] = step + 1;
            search(nx, ny, step + 1);
            map[nx][ny] = 0;
        }
    }
}

void print()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            printf("%02d ", map[i][j]);
        }
        putchar('\n');
    }
}

int check(int x, int y)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
    {
        return 0;
    }
    if (map[x][y] != 0)
    {
        return 0;
    }
    return 1;
}

void mrand()
{
    int r = rand() % 8;
    int temp = dx[0];
    dx[0] = dx[r];
    dx[r] = temp;
    temp = dy[0];
    dy[0] = dy[r];
    dy[r] = temp;
}
