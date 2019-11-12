#include <stdio.h>

#define MAXM 1000000

//m as the greatest prime
void createPrimeTable(int m);

int tb[MAXM + 1]; //tb as the Prime Table

int main()
{
    int m;
    scanf("%d", &m);
    int i;
    for (i = 2; i <= m; ++i)
    {
        tb[i] = 1;
    }
    createPrimeTable(m);

    for (i = 3; i + 2 <= m; i += 2)
    {
        if (tb[i] && tb[i + 2])
        {
            printf("(%d, %d)  ", i, i + 2);
        }
    }

    return 0;
}

void createPrimeTable(int m)
{
    int i, j;
    tb[0] = tb[1] = 0;
    tb[2] = 1;
    for (i = 2; i <= m; ++i)
    {
        if (tb[i])
        {
            for (j = 2; i * j <= m; ++j)
            {
                tb[i * j] = 0;
            }
        }
    }
}
