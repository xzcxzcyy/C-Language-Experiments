/*
 * strnins()函数实现：
 * 字符串插入函数
 */

#include <stdio.h>
#include <string.h>

void strnins(char *t, char *s, int n);

int main()
{
    setbuf(stdout, NULL);
    char t[200];
    char s[80];
    int n;
    printf("Please input string t, s and integer n:\n");
    scanf("%s %s %d", t, s, &n);
    strnins(t, s, n);
    puts(t);
    return 0;
}

void strnins(char *t, char *s, int n)
{
    int length = strlen(s);
    int i;
    for (i = strlen(t); i >= n; --i)
    {
        t[i + length] = t[i];
    }
    int j;
    for (i = n, j = 0; s[j] != '\0'; ++i, ++j)
    {
        t[i] = s[j];
    }
}
