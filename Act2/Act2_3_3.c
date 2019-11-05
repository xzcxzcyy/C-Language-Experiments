#include <stdio.h>

int main()
{
    char ch;
    int cnt = 0;
    int success = 1;
    while ((ch = getchar()) != EOF && success)
    {
        ++cnt;
        if (cnt == 12 && ch == '\n')
        {
            --cnt;
            break;
        }
        if (!(ch >= '0' && ch <= '9'))
        {
            success = 0;
            break;
        }
        switch (cnt)
            /*借用一部分自动机的思想，通过判断 cnt 来判断处于第几位*/
        {
            case 1:
                if (ch != '1')
                {
                    success = 0;
                }
                break;
            case 2:
                if (!(ch == '3' || ch == '4' || ch == '5' || ch == '7' || ch == '8'))
                {
                    success = 0;
                }
                break;
            default:
                if (cnt > 11)
                {
                    success = 0;
                }
                break;
        }
    }
    if (cnt != 11)
    {
        success = 0;
    }

    if (success)
    {
        printf("This is a phone number\n");
    } else
    {
        printf("This is NOT a phone number\n");
    }
    return 0;
}
