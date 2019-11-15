/*
 * 条件编译输出大小写
 */

#include <stdio.h>

#define CHANGE 1

char change(char ch);

int main()
{
    setbuf(stdout, NULL);
    printf("Please input a set of letter(s):\n");
    char ch;
    while ((ch = getchar()) != EOF)
    {
        /*
         * 使用预编译指令 #if 来进行处理，判断宏 CHANGE 的值
         */
#if CHANGE
        ch = change(ch);
#endif
        putchar(ch);
    }
}

/*
 * 定义大小写互换函数 change()
 */
char change(char ch)
{
    int diff = 'a' - 'A';
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + diff;
    } else if (ch >= 'a' && ch <= 'z')
    {
        return ch - diff;
    }
    return ch;
}
