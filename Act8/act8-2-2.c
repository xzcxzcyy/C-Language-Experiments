#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char ch;
    FILE *fp;
    if (argc != 2 && argc != 3)
    {
        printf("Arguments error!\n");
        exit(-1);
    }
    char *name = argv[1];
    int part = 0;
    if (argc == 3)
    {
        if (strcmp(argv[1], "/p") == 0)
        {
            name = argv[2];
            part = 1;
        }
        else if (strcmp(argv[2], "/p") == 0)
        {
            name = argv[1];
            part = 1;
        }
        else
        {
            printf("Arguments error!\n");
            exit(-1);
        }
    }
    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s file!\n", name);
        exit(-1);
    }

    static char buf[100];
    if (part)
    {
        char cmd;
        do
        {
            int l = 1;
            while (l <= 25 && fgets(buf, 100, fp) != NULL) //利用了短路运算性质，前后不可颠倒
            {
                fprintf(stdout, "%02d  ", l);
                fputs(buf, stdout);
                ++l;
            }
            system("pause");
        } while (!feof(fp)); // Press q to quit
    }
    else
    {
        int l = 1;
        while (fgets(buf, 100, fp) != NULL) //利用了短路运算性质，前后不可颠倒
        {
            fprintf(stdout, "%02d  ", l);
            fputs(buf, stdout);
            ++l;
        }
    }
    fclose(fp);
    return 0;
}
