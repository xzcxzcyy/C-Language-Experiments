#include <stdio.h>
#include <math.h>

int main()
{
    int a = 1, b = 0;
    int current;
    for (a = 1; a <= 9; ++a)
    {
        for (b = 0; b <= 9; ++b)
        {
            /* To guarantee that the two numbers do not equal. */
            if (a != b)
            {
                /* To combine the digits and make up a number. */
                current = a * 1000 + a * 100 + b * 10 + b;
                if ((int) sqrt(current) * (int) sqrt(current) == current)
                {
                    printf("%d\n ", current);
                }
            }
        }
    }
    return 0;
}
