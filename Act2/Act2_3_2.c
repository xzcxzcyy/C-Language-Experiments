#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int cpn = n;
    /*用来保存原始的输入数据*/
    int i;
    int sum = 0;
    for (i = 0; n != 0; i++)
    {
        sum += (n - n / 10 * 10);
        /*将n目前的个位数字提取出来并加到累加变量 sum 上*/
        n /= 10;
    }
    printf("%d是%d位数，各位数字之和为%d", cpn, i, sum);
    return 0;
}
