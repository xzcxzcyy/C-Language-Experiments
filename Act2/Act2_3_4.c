#include <stdio.h>

enum state
{
    init, up, down
};

int main()
{
    int n;
    printf("Please input the number of day(s)\n");
    scanf("%d", &n);
    printf("Please input the %d numbers\n", n);
    enum state current = init;
    int cnt = 0;
    int i;
    int previous = -1, temp;
    /*变量 previous 保存之前一天的销售量，变量 temp 保存当天的销售量，以此来判断是上升状态还是下降状态。*/

    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &temp);
        switch (current)
            /*使用有限状态自动机，定义三个状态 init,up,down ，其中 init 状态可能有两种情况*/
        {
            case init:
                if (i == 2)
                {
                    current = temp > previous ? up : down;
                }
                break;
            case up:
                if (temp < previous)
                {
                    ++cnt;
                    current = down;
                }
                break;
            case down:
                if (temp > previous)
                {
                    ++cnt;
                    current = up;
                }
                break;
            default:
                printf("State Error.\nUnexpected state id %d", current);
        }
        previous = temp;
    }
    printf("%d", cnt);
    return 0;
}
