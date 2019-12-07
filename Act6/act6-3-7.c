/*
 * 函数调度
 */

#include <stdio.h>

#define N 8

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void scheduler();
void execute(void (**p)(), int n);

int main()
{
    scheduler();
    return 0;
}

void task0()
{
    puts("task0 is called!");
}

void task1()
{
    puts("task1 is called!");
}

void task2()
{
    puts("task2 is called!");
}

void task3()
{
    puts("task3 is called!");
}

void task4()
{
    puts("task4 is called!");
}

void task5()
{
    puts("task5 is called!");
}

void task6()
{
    puts("task6 is called!");
}

void task7()
{
    puts("task7 is called!");
}

void scheduler()
{
    int p = 0;
    void (*funcPtrArr[N])();
    funcPtrArr[0] = task0;
    funcPtrArr[1] = task1;
    funcPtrArr[2] = task2;
    funcPtrArr[3] = task3;
    funcPtrArr[4] = task4;
    funcPtrArr[5] = task5;
    funcPtrArr[6] = task6;
    funcPtrArr[7] = task7;
    char cmd;
    void (*funcPtrCalling[50])();
    while ((cmd = getchar()) != '\n')
    {
        funcPtrCalling[p++] = funcPtrArr[cmd - '0'];
    }
    execute(funcPtrCalling, p);
}

void execute(void (**p)(), int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i]();
    }
}
