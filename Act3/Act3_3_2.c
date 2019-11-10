#include <stdio.h>

double mabs(double x);

int main()
{
    setbuf(stdout, NULL);
    int n;
    printf("Please enter the number of day(s): \n");
    scanf("%d", &n);
    double pre, cur; //previous, current
    scanf("%lf", &pre);
    int i;
    double maxdelta = 0.0;
    for (i = 1; i < n; ++i)
    {
        scanf("%lf", &cur);
        if (mabs(cur - pre) > maxdelta)
        {
            maxdelta = mabs(cur - pre);
        }
        pre = cur;
    }
    printf("Max of delta: %lf\n", maxdelta);
    return 0;
}

double mabs(double x)
{
    return x >= 0 ? x : -x;
}
