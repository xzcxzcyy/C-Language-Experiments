#include <stdio.h>

double mabs(double x);
void search(int stage, double a, double b);

int success = 0;
int total = 0;

int main()
{
    search(0, 1000, 2000);
    printf("Theoretical possibility: %f\n", (double) success / total);
    return 0;
}

double mabs(double x)
{
    return x >= 0 ? x : -x;
}

void search(int stage, double a, double b)
{
    if (stage == 4)
    {
        ++total;
        if (mabs(a - b) < 1000)
        {
            ++success;
        }
        return;
    }

    search(stage + 1, a + b / 4, b - b / 4);
    search(stage + 1, a - a / 4, b + a / 4);
}
