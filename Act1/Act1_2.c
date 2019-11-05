#include <stdio.h>

int main(void)
{
    char c, numchar, numline;
    numchar = 0;
    numline = 0;
    printf("输入若干行文本，Ctrl+z结束\n");
    while ((c = getchar()) != EOF)
        /*语义错误: !=的优先级高于=，因此未遇到EOF时，总是先计算出1，再复制给c。加括号解决这个问题。*/
    {
        numchar++;
        if (c == '\n')
            numline++;
    }
    printf("字符数：%d, ", numchar);
    /*Warning: 采取了后缀自增运算符 (numchar++) ，因此并未对程序的正确性产生影响。但出于简洁性和易读性的考虑，应予修改*/
    printf("行数：%d\n", numline);
    return 0;
}
