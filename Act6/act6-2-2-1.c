/*
 * 字符串复制，连接与分割
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    setbuf(stdout, NULL);
    char *(*p)(char *x, const char *y); //1st blank
    char a[80], b[80], *result;
    int choice;
    while (1)
    {
        do
        {
            printf("\t\t1 copy string.\n");
            printf("\t\t2 connect string.\n");
            printf("\t\t3 Parse string.\n");
            printf("\t\t4 exit.\n");
            printf("\t\tinput a number (1-4) please!\n");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);
        switch (choice)
        {
            case 1:
                p = strcpy;
                break;

            case 2:
                p = strcat;
                break;

            case 3:
                p = strtok;
                break;

            case 4:
                goto down;
                break;
        }
        getchar();
        printf("input the first string please!\n");
        gets(a); //2nd blank
        printf("input the second string please!\n");
        gets(b); //3rd blank
        result = p(a, b); //4th blank
        printf("the result is %s\n", result);
    }
    down:
    return 0;
}
