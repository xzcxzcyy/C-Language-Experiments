#include <stdio.h>

void strReverse(char s[]);
int strLength(char s[]);

int main()
{
    char s[1000];
    printf("输入一个字符串\n");
    scanf("%s", s);
    printf("串%s的长度为：%d\n", s, strLength(s));
    strReverse(s);
    printf("反转后:%s", s);
    return 0;
}

int strLength(char s[])
{
    int i = 0;
    while (s[i++]);
    return i - 1;
    /*返回i之前，i已经被自增。因此i的值比实际值大1，故修改为 return i-1;*/
}

void strReverse(char s[])
{
    int i, j;
    for (i = 0, j = strLength(s) - 1; i < j; i++, j--)
        /*数组越界：j指向了不存在的值。修改为j = strLength(s) - 1;*/
    {
        char t;
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}
