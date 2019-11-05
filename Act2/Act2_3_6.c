#include <stdio.h>

int main()
{
    unsigned long int code;
    scanf("%lu", &code);
    unsigned long int mask = 0xff;
    unsigned long res[4];
    int i;
    for (i = 0; i < 4; ++i)
    {
        res[i] = code & mask;
        code >>= 8;
    }
    /*应当倒序输出，因为最低位所代表的数应当最后输出*/
    printf("%lu", res[3]);
    for (i = 2; i >= 0; --i)
    {
        putchar('.');
        printf("%lu", res[i]);
    }
    return 0;
}
