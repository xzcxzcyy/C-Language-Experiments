#include <stdio.h>

int main()
{
    unsigned short x, m, n;
    unsigned short mask;
    scanf("%hx %hu %hu", &x, &m, &n);
    if (m >= 0 && m <= 15 && n >= 1 && n <= 16 - m)
    {
        mask = -1u >> m << m << (32 - m - n) >> (32 - m - n);
        /*这里为了处理整数提升造成的麻烦进行了特殊处理：左移时额外多移了16位*/
        x &= mask;
        x <<= (16 - m - n);
        printf("%x\n", x);
    } else
    {
        printf("Illegal m or n\n");
    }
    return 0;
}
