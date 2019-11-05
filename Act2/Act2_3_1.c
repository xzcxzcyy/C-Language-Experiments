#include <stdio.h>

char toLower(char ch)
{
    if (!(ch >= 'A' && ch <= 'Z'))
        /* 检查数据合法性 */
    {
        printf("Error in function toLower(char): parameter is not an upper letter\n");
        return '\0';
    }
    return ch - ('A' - 'a');
}

int main()
{
    printf("Please enter a character\n");
    char ch;
    ch = getchar();
    if (ch >= 'A' && ch <= 'Z')
        /* 判断是否为大写字母 */
    {
        putchar(toLower(ch));
    } else
    {
        putchar(ch);
    }
    return 0;
}
