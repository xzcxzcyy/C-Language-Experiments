#ifndef ACT4_FILE_H
#define ACT4_FILE_H

#include <stdio.h>

/*
 * 引用型声明，是为了让所有包含本头文件的文件可以访问 x, y 和 ch。
 */
extern int x, y;
extern char ch;

void func1(void);

#endif //ACT4_FILE_H
