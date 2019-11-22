/*
 * 程序完善：文本去重
 */

#include <stdio.h>
#include <string.h>

void RemoveDuplicate(char *s);

int main()
{
    char str[200];
    printf("Input strings,end of Ctrl+z\n");
    while (fgets(str, 200, stdin) != NULL)
    {
        RemoveDuplicate(str);
        printf("%s", str);
    }
    return 0;
}

void RemoveDuplicate(char *s)
{
    int r, w, i, len;
    static int occurred[256] = {0};

    len = strlen(s);
    for (r = w = 0; r < len; r++)
    {
        if (occurred[s[r]] == 0) // decide whether s[r] has occurred or not
        {
            s[w++] = s[r];
            occurred[s[r]] = 1; // declare the occurrence of s[r]
        }
    }
    s[w] = '\0';
}
