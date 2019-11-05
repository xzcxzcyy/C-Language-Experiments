#include <stdio.h>

/* 判断年份 y 是否是闰年 */
int isRun(int y)
{
    if (y % 100 == 0)
    {
        if (y % 400 == 0)
        {
            return 1;
        }
    } else
    {
        if (y % 4 == 0)
        {
            return 1;
        }
    }

    return 0;
}

/* 返回某月有几天 */
int dayOfMonth(int m, int isR)
{
    switch (m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if (isR)
            {
                return 29;
            } else
            {
                return 28;
            }
    }
}

int main()
{
    int year, d;
    scanf("%d %d", &year, &d);
    int i;
    int dom; /* day of month */
    for (i = 1; i <= 12; ++i)
    {
        dom = dayOfMonth(i, isRun(year));
        if (d - dom == 0)
        {
            d -= dom;
            break;
        }
        if (d - dom < 0)
        {
            --i;
            break;
        }
        d -= dom;
    }
    if (d == 0)
    {
        printf("%d月%d日\n", i, dayOfMonth(i, isRun(year)));
    } else
    {
        printf("%d月%d日\n", i + 1, d);
    }
    return 0;
}
