#include <stdio.h>

int fsm_unit(char end);
int is_digit(char ch);

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
        //TODO: COMPLETE THE OUTPUT:
        // You should turn the legal IP to an int as told in the experiment's guide.
        printf("success\n");
    } else
    {
        printf("illegal IP address.\n");
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
