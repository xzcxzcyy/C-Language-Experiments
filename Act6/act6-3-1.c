/*
 * 按位显示
 */

#include <stdio.h>

union Test
{
    int num;
    char arr[4];
};

enum Type
{
    big, small
};

// 用于获取本机是大端法还是小端法
enum Type getType();

int main()
{
    setbuf(stdout, NULL);
    long a;
    puts("Please enter a number");
    scanf("%ld", &a);
    unsigned char *p; // 注意：用 unsigned char * 是为了规避后续的整数提升带来的问题
    int step;
    if (getType() == small)
    {
        p = (char *) &a + 3;
        step = -1;
    } else
    {
        p = (char *) &a;
        step = 1;
    }
    int i;
    for (i = 0; i < 4; ++i)
    {
        unsigned char temp = *p;
        printf("%x ", temp >> 4);
        printf("%x ", temp & 0xf);
        p += step;
    }
    return 0;
}

enum Type getType()
{
    union Test u;
    u.num = 1;
    if (u.arr[0] == 1)
    {
        return small;
    } else
    {
        return big;
    }
}
