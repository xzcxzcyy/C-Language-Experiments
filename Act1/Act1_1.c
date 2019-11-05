#include <math.h>
#include <stdio.h>

int main()
{
    long x, y;
    int i;
    for (i = 1; i <= 100000; i++)
        /*未声明的变量使用: i 在此作用域内未被声明*/
        /*Warning: 100000并没有被检查（虽然它并不属于答案）*/
    {
        x = sqrt(i + 100);
        y = sqrt(i + 268);
        if (x * x == i + 100 && y * y == i + 268)
            /*表达式的比较: 期望 == , 实际为 = */
            /*语法错误: if 语句的括号位置和数量错误*/
            printf("\n%d", i);
        /*Warning: 存在前导空行*/
    }
    return 0;
}
