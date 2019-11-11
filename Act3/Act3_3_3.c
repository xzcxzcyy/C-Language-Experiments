#include <stdio.h>

enum Type
{
    other, blank
};

enum State
{
    init, bl
};

int getType(char ch);

int main()
{
    setbuf(stdout, NULL);
    enum State current = init;
    char ch;
    printf("Please enter some characters.\nPress Ctrl + D to quit.\n");
    while ((ch = getchar()) != EOF)
    {
        switch (current)
        {
            case init:
                if (getType(ch) == other)
                {
                    putchar(ch);
                }
                if (getType(ch) == blank)
                {
                    current = bl;
                }
                break;

            case bl:
                if (getType(ch) == blank);
                if (getType(ch) == other)
                {
                    putchar(' ');
                    putchar(ch);
                    current = init;
                }
                break;
        }
    }
    return 0;
}

int getType(char ch)
{
    switch (ch)
    {
        case ' ':
            return blank;

        default:
            return other;
    }
}
