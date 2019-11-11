#include <stdio.h>

double m_abs(double x);
void search(int stage, double a, double b);

int success = 0;
int total = 0;

int main()
{
    search(0, 1000, 2000);
    printf("Theoretical possibility: %f\n", (double) success / total);
    return 0;
}

double m_abs(double x)
{
    return x >= 0 ? x : -x;
}

/*
 * 将使用递归法搜索符合条件的情况
 * stage 用来保存已经进行过的场次数
 * a 和 b分别为甲和乙的当前体力值
 */
void search(int stage, double a, double b)
{
    if (stage == 4)
    {
        ++total;
        if (m_abs(a - b) < 1000)
        {
            ++success;
        }
        return;
    }

    /*
     * 如果尚未达到阶段4，那么就搜索下一阶段的情况
     * 有两种可能
     */
    search(stage + 1, a + b / 4, b - b / 4);
    search(stage + 1, a - a / 4, b + a / 4);
}
