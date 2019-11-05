#include <stdio.h>

#define PI 3.14159

int main(void)
{
    int f;
    short p, k;
    double c, r, s;

    /*任务1*/

    printf("Input Fahrenheit:");
    scanf("%d", &f);
    /*运行时出错: 期望传递 f 的地址，实际传递 f 的值。*/
    c = 5.0 / 9 * (f - 32);
    /*语义错误: 由于隐式类型转换，c的值恒为0*/
    printf("\n %d (F) = %.2f(C)\n\n", f, c);

    /*任务2*/

    printf("input the radius r:");
    scanf("%lf", &r);
    /*语义错误：输入 double 类型的值应该使用占位符 %lf*/
    s = PI * r * r;
    printf("\nThe acreage is %.2f\n\n", s);
    /*语义错误：应当打印 s 的值，而不是其地址*/

    /*任务3*/

    k = 0xa1b2, p = 0x8423;
    short newint = p & 0xff00 | (unsigned short)k >> 8;
    /*语法错误：变量 newint 未声明就使用*/
    /*语义错误：k 值越界（k是 short 类型），溢出到负数，右移时补 1 ，这与预期补0不符，
     * 通过强制类型转换转换为 unsigned short 解决*/
    printf("new int = %#hx\n\n", newint);
    /*语义错误：打印short类型应该添加长度修饰符 h 到x之前*/
    return 0;

}
