#include <stdio.h>

/* m_abs() returns the absolute value of a double*/
double m_abs(double x);

int main()
{
    setbuf(stdout, NULL);
    int n;
    printf("Please enter the number of day(s): \n");
    scanf("%d", &n);
    double pre, cur; //previous, current
    scanf("%lf", &pre);
    int i;
    double maxdelta = 0.0; //delta of max
    for (i = 1; i < n; ++i)
    {
        scanf("%lf", &cur);
        if (m_abs(cur - pre) > maxdelta)
        {
            maxdelta = m_abs(cur - pre);
        }
        pre = cur;
    }
    printf("Max of delta: %lf\n", maxdelta);
    return 0;
}

double m_abs(double x)
{
    return x >= 0 ? x : -x;
}
