#include <stdio.h>

int isPerfect(int x)
{
    int y, s;
    for (s = 0, y = 1; y <= x / 2; y++)
        /*单步到此处可以看到，y=x/2时恰为被判断，因此修改循环条件为y <= x / 2*/
    {
        if (!(x % y))
            s += y;
    }
    if (s == x)
        return 1;
    return 0;
}

int main()
{
    int a;
    printf("1000内的完数有：");
    for (a = 1; a <= 1000; a++)
        if (isPerfect(a))
            printf("%8d", a);
    return 0;
}
