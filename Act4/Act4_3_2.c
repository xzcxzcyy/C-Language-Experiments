/* 
 * 计算圆的面积
 * 以及面积的整数部分
 */

#include <stdio.h>
#include <assert.h>
#define R

/* 
 * 错误： assert.h 没有 include 
 * 错误： integer_fraction() 在调用前没有声明
 */

int integer_fraction(float x);

int main(void)
{
    float r, s;
    int s_integer = 0;
    printf("input a number: ");
    scanf("%f", &r);
#ifdef R
    s = 3.14159 * r * r;
    printf("area of round is: %f\n", s);
    s_integer = integer_fraction(s);

    /* 失败原因：总是向下取整，导致误差有时超过 0.5 */

    assert((s - s_integer) < 0.5);
    printf("the integer fraction of area is %d\n", s_integer);
#endif
    return 0;
}

int integer_fraction(float x)
{
    int i = x;
    /* 利用三目运算符实现四舍五入 */
    return x - i >= 0.5 ? i + 1 : i;
}
