#include <stdio.h>

double tax1(double s);
double tax2(double s);

int main()
{
    setbuf(stdout, NULL);
    double salary;
    printf("Please enter your salary:\n");
    scanf("%lf", &salary);
    printf("Tax to be paid: %10.2lf %10.2lf", tax1(salary), tax2(salary));
    return 0;
}

double tax1(double s)
{
    if (s < 1000)
    {
        return 0;
    }
    if (s >= 1000 && s < 2000)
    {
        return s * 0.05;
    }
    if (s >= 2000 && s < 3000)
    {
        return s * 0.10;
    }
    if (s >= 3000 && s < 4000)
    {
        return s * 0.15;
    }
    if (s >= 4000 && s < 5000)
    {
        return s * 0.20;
    }
    if (s >= 5000)
    {
        return s * 0.25;
    }

    /* -1 for bug tracking */
    return -1;
}

double tax2(double s)
{
    double rate;
    switch ((int) s / 1000)
        /* 转换为整数再除以1000，是为了得到工资的首位数字 */
    {
        case 0:
            rate = 0.00;
            break;

        case 1:
            rate = 0.05;
            break;

        case 2:
            rate = 0.10;
            break;

        case 3:
            rate = 0.15;
            break;

        case 4:
            rate = 0.20;
            break;

        case 5:
            rate = 0.25;
            break;

        default:
            /* -1 for bug tracking */
            rate = -1.0;
            break;
    }
    return s * rate;
}
