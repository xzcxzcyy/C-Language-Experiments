#include <stdio.h>

int main()
{
    setbuf(stdout, NULL);
    int i, x, k, flag = 0;
    printf("本程序判断合数，请输入大于1的整数，Ctrl+z结束\n");
    while (scanf("%d", &x) != EOF)
    {
        /*
         * 注意到在循环输入时没有重置 flag, 这就导致只要有一次 flag 被置为1，flag的初值在下次循环就是1
         */
        flag = 0;
        for (i = 2, k = x >> 1; i <= k; i++)
        {
            if (!(x % i))
                /* !运算符优先级较高 */
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            /* 错误地使用了赋值运算符 */
        {
            printf("%d 是合数\n", x);
        } else
        {
            printf("%d 不是合数\n", x);
        }
    }
    return 0;
}
