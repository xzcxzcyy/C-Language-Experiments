#include <stdio.h>

int fsm_unit(char end);
int is_digit(char ch);

/*
 * fsm_unit函数负责匹配1~3个合法数字+一个结束符，所谓合法是指表示数介于0~255
 * 对于前三节，结束符是 '.'；
 * 对于最后一节，结束符是 '\n'。
 */

int main()
{
    int a[4];
    int state = 0;
    while (state != -1 && state != 4)
    {
        switch (state)
        {
            case 0:
            case 1:
            case 2:
                a[state] = fsm_unit('.');
                if (a[state] != -1)
                {
                    ++state;
                } else
                {
                    state = -1;
                }
                break;

            case 3:
                a[state] = fsm_unit('\n');
                if (a[state] != -1)
                {
                    state = 4;
                } else
                {
                    state = -1;
                }
                break;

            default:
                printf("State error in the main FSM\n");
                break;
        }
    }
    if (state == 4)
    {
        int i;
        unsigned long int converted_ip = 0;
        for (i = 0; i < 4; ++i)
        {
            converted_ip = (converted_ip << 8) + a[i];
        }
        printf("YES\n%lu", converted_ip);
    } else
    {
        printf("NO\n");
    }
}

int fsm_unit(char end)
{
    char ch;
    int state = 1;
    int result = 0;
    while (state != 0 && state != 5)
    {
        ch = getchar();
        switch (state)
        {
            case 1:
                if (is_digit(ch))
                {
                    result = result * 10 + (ch - '0');
                    state = 2;
                } else
                {
                    state = 0;
                }
                break;

            case 2:
            case 3:
                if (is_digit(ch))
                {
                    result = result * 10 + (ch - '0');
                    ++state;
                } else if (ch == end)
                {
                    state = 5;
                } else
                {
                    state = 0;
                }
                break;

            case 4:
                if (ch == end)
                {
                    state = 5;
                } else
                {
                    state = 0;
                }
                break;

            default:
                printf("FSM error\n");
                break;
        }
    }
    if (state == 5 && result >= 0 && result <= 255)
    {
        return result;
    } else
    {
        return -1;
    }
}

int is_digit(char ch)
{
    return ch >= '0' && ch <= '9';
}
