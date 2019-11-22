/*
 * 程序完善：文本去重
 */

#include <stdio.h>
#include <string.h>

void RemoveDuplicate(char *s); //1st blank: declaration of the function before function call

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
    len = strlen(s);
    for (r = w = 0; r < len; r++)
    {
        if (s[r] != '\0') // 2nd blank: to decide whether s[r] has been deleted
        {
            s[w++] = s[r]; //3rd blank: copy the character and move pointer w
            for (i = r + 1; i < len; i++)
            {
                if (s[i] == s[r]) // 4th blank: to decide whether s[i] shall be deleted
                {
                    s[i] = '\0';
                }
            }
        }
    }
    s[w] = '\0'; // 5th blank: to add '\0' as the end of string
}
