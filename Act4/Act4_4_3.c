/*
 * 计算三角形面积
 */

#include <stdio.h>
#include <math.h>

/* 注意：由于宏展开的性质，应当在表达式两侧加括号 */
#define S(a, b, c) ((a+b+c)/2)
#define AREA(s, a, b, c) (sqrt(s*(s-a)*(s-b)*(s-c)))

int main()
{
    setbuf(stdout, NULL);
    double a, b, c;
    printf("Please input a, b, and c: \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    double s = S(a, b, c);
    double area = AREA(s, a, b, c);
    printf("Area: %f\n", area);
    return 0;
}
