#include <stdio.h>

int main()
{
    setbuf(stdout, 0);
    int i, x, k, flag = 0;
    int cx; //cope of x
    int is_complete; //是否为完全合数
    int count = 0; //完全合数的个数
    for (x = 100; x <= 999; ++x)
    {
        is_complete = 1;
        for (cx = x; cx != 0; cx /= 10)
        {
            flag = 0;
            for (i = 2, k = cx >> 1; i <= k; ++i)
            {
                if (!(cx % i))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                continue;
            } else
            {
                is_complete = 0;
            }
        }

        if (is_complete)
        {
            /*
             * 按照每行五个的格式输出结果
             */
            printf("%4d ", x);
            ++count;
            if (count % 5 == 0)
            {
                putchar('\n');
            }
        }
    }
    return 0;
}
