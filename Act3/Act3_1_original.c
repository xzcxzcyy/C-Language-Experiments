#include <stdio.h>

int main()
{
    int i, x, k, flag = 0;
    printf("本程序判断合数，请输入大于1的整数，Ctrl+z结束\n");
    while (scanf("%d", &x) != EOF)
    {
        for (i = 2, k = x >> 1; i <= k; i++)
        {
            if (!x % i)
            {
                flag = 1;
                break;
            }
        }
        if (flag = 1)
        {
            printf("%d 是合数\n", x);
        } else
        {
            printf("%d 不是合数\n", x);
        }
    }
    return 0;
}
