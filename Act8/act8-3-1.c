/*
 * 字符串替换
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000

int equal(const char *source, const char *pat);

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fputs("Arguments Error\n", stderr);
        exit(-1);
    }
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL)
    {
        fputs("Cannot open this file\n", stderr);
        exit(-1);
    }

    char *buf = malloc(SIZE * sizeof(char));
    char *tar = malloc(SIZE * sizeof(char));

    int i = 0;
    while (i < SIZE - 1 && !feof(fin))
    {
        buf[i] = fgetc(fin);
        ++i;
    }
    buf[i - 1] = '\0';

    char *pat = argv[3];
    char *rep = argv[2];
    int totalLen = strlen(buf);
    int patLen = strlen(pat);
    int repLen = strlen(rep);
    int w = 0;
    int cnt = 0;

    i = 0;
    while (i < totalLen)
    {
        if (equal(buf + i, pat))
        {
            ++cnt;
            for (int j = 0; j < repLen; ++j)
            {
                tar[w++] = rep[j];
            }
            i += patLen;
        }
        else
        {
            tar[w++] = buf[i];
            i += 1;
        }
    }
    tar[w] = '\0';
    fclose(fin);

    FILE *fout = fopen(argv[1], "w");
    if (fout == NULL)
    {
        fputs("Error occurred when trying to write to the file.\n", stderr);
        exit(-1);
    }

    fputs(tar, fout);
    fclose(fout);
    printf("Replaced %d time(s)\n", cnt);
    return 0;
}

int equal(const char *source, const char *pat)
{
    int i;
    int sl = strlen(source), pl = strlen(pat);
    for (i = 0; i < pl && i < sl; ++i)
    {
        if (source[i] != pat[i])
        {
            break;
        }
    }
    return i == pl;
}
