#include <stdio.h>

int main(void)
{
    short a = 0x253f, b = 0x7b7d;
    char ch;
    FILE *fp1, *fp2;
    fp1 = fopen(".\\test1.bin", "wb+");
    fp2 = fopen(".\\test2.txt", "w+");
    //fwrite(&a, sizeof(short), 1, fp1);
    //fwrite(&b, sizeof(short), 1, fp1);
    fwrite(&a, sizeof(char), 1, fp1);
    fwrite(&b, sizeof(char), 1, fp1);
    /*
     * 由于目前处于小端机器，指针指向的是低字节
     */
    fprintf(fp2, "%d %d", a, b);

    rewind(fp1);
    rewind(fp2);
    while ((ch = fgetc(fp1)) != EOF) //fgetc()将读取一个字节并解释为整数
    {
        putchar(ch);
    }
    putchar('\n');
    while ((ch = fgetc(fp2)) != EOF)
    {
        putchar(ch);
    }
    putchar('\n');

    fclose(fp1);
    fclose(fp2);
    return 0;
}
