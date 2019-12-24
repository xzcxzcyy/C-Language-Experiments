/*
 * 单精度浮点数
 */

#include <stdio.h>

int main()
{
    float arr[10];
    for (int i = 0; i < 10; ++i)
    {
        scanf("%f", &arr[i]);
    }

    FILE *fout = fopen("float.dat", "w");
    if (fout == NULL)
    {
        fputs("Can't create file \"float.dat\"\n", stderr);
        exit(-1);
    }

    fwrite(arr, sizeof(float), 10, fout);
    fclose(fout);

    float read[10];
    FILE *fin = fopen("float.dat", "r");
    if (fin == NULL)
    {
        fputs("Reading Error\n", stderr);
        exit(-1);
    }
    fread(read, sizeof(float), 10, fin);

    for (int i = 0; i < 10; ++i)
    {
        printf("%f ", read[i]);
    }
    putchar('\n');
    return 0;
}
