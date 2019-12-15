/*
 * 8个函数指针
 */

#include <stdio.h>

void f0(int b)
{
    printf("Function 0 is called!\tbit0 is %d.\n", b);
}

void f1(int b)
{
    printf("Function 1 is called!\tbit1 is %d.\n", b);
}

void f2(int b)
{
    printf("Function 2 is called!\tbit2 is %d.\n", b);
}

void f3(int b)
{
    printf("Function 3 is called!\tbit3 is %d.\n", b);
}

void f4(int b)
{
    printf("Function 4 is called!\tbit4 is %d.\n", b);
}

void f5(int b)
{
    printf("Function 5 is called!\tbit5 is %d.\n", b);
}

void f6(int b)
{
    printf("Function 6 is called!\tbit6 is %d.\n", b);
}

void f7(int b)
{
    printf("Function 7 is called!\tbit7 is %d.\n", b);
}

struct bits
{
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

int main()
{
    setbuf(stdout, NULL);
    void (*p_fun[8])(int b);

    p_fun[0] = f0;
    p_fun[1] = f1;
    p_fun[2] = f2;
    p_fun[3] = f3;
    p_fun[4] = f4;
    p_fun[5] = f5;
    p_fun[6] = f6;
    p_fun[7] = f7;

    struct bits b;
    int a = -1;
    b = *(struct bits *) &a;

    if (b.bit0)
    {
        p_fun[0](b.bit0);
    }
    if (b.bit1)
    {
        p_fun[1](b.bit1);
    }
    if (b.bit2)
    {
        p_fun[2](b.bit2);
    }
    if (b.bit3)
    {
        p_fun[3](b.bit3);
    }
    if (b.bit4)
    {
        p_fun[4](b.bit4);
    }
    if (b.bit5)
    {
        p_fun[5](b.bit5);
    }
    if (b.bit6)
    {
        p_fun[6](b.bit6);
    }
    if (b.bit7)
    {
        p_fun[7](b.bit7);
    }
}
