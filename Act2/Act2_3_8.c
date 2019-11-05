#include <stdio.h>

enum State
{
    init, cn1, cn2, en
};

enum Type
{
    tcn, ten, empty, other
    /* type_cn, type_en, type_empty, type_other */
};

int getType(int x)
{
    if (x >= 128)
    {
        return tcn;
    }
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
    {
        return ten;
    }
    if (x == ' ' || x == '\n' || x == '\t')
    {
        return empty;
    }
    return other;
}

int main()
{
    /* 利用getchar()返回值位模式首位是否为1来判断一个字符是否属于中文字符 */
    /* 中文字符表示方式由平台决定，在当前 Windows 环境下，需要用三个 getchar() 来读完一个中文字符 */
    /* 采用 FSM 解决这个问题 */
    setbuf(stdout, 0);//I have to use setbuf() because of a bug of my IDE, sorry for that.
    enum State current = init;
    int temp;
    int words = 0, chars = 0, lines = 0;
    while ((temp = getchar()) != EOF)
    {
        switch (current)
        {
            case init:
                if (getType(temp) == tcn)
                {
                    current = cn1;
                    break;
                }
                if (getType(temp) == ten)
                {
                    ++chars;
                    current = en;
                    break;
                }
                if (getType(temp) == empty)
                {
                    if (temp == '\n')
                    {
                        ++lines;
                    }
                    break;
                }
                if (getType(temp) == other)
                {
                    ++chars;
                    break;
                }
                break;

            case cn1:
                if (getType(temp) == tcn)
                {
                    current = cn2;
                }
                break;

            case cn2:
                if (getType(temp) == tcn)
                {
                    ++words;
                    ++chars;
                    current = init;
                }
                break;

            case en:
                if (getType(temp) == tcn)
                {
                    ++words;
                    current = cn1;
                }
                if (getType(temp) == ten)
                {
                    ++chars;
                }
                if (getType(temp) == empty)
                {
                    if (temp == '\n')
                    {
                        ++lines;
                    }
                    ++words;
                    current = init;
                }
                if (getType(temp) == other)
                {
                    ++words;
                    ++chars;
                    current = init;
                }
                break;
        }
    }
    printf("字数：%d\n字符数：%d\n行数：%d\n", words, chars, lines);
    return 0;
}
