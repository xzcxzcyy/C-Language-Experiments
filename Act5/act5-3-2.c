#include <stdio.h>
#include <stdlib.h>

#define MAX 100

double scores[MAX];
char *names[MAX];
int n;

enum Option
{
    oInput, oOutput, oFind
};

void input(int n);
void output(int n);
void mqsort(int begin, int end); //my quick sort
void sswap(double *a, double *b); //score swap
void nswap(char **a, char **b); //name swap
enum Option menu();

int main()
{

    return 0;
}

void input(int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        names[i] = malloc(30 * sizeof(char));
        scanf("%s", names[i]);
        scanf("%lf", &scores[i]);
    }
}

void output(int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%s", names[i]);
        printf("%8.2f\n", scores[i]);
    }
}

void nswap(char **a, char **b)
{
    char *t;
    t = *a;
    *a = *b;
    *b = t;
}

void sswap(double *a, double *b)
{
    double t;
    t = *a;
    *a = *b;
    *b = t;
}

void mqsort(int begin, int end)
{
    if (end - begin <= 1)
    {
        return;
    }
    int i = begin, j = end - 1;
    double pivot = scores[i + (j - i) / 2];
    while (i <= j)
    {
        while (scores[i] > pivot)
        {
            ++i;
        }
        while (scores[j] < pivot)
        {
            --j;
        }
        if (i <= j)
        {
            sswap(scores + i, scores + j);
            nswap(names + i, names + j);
            ++i;
            --j;
        }
    }
    mqsort(begin, j + 1);
    mqsort(i, end);
}

enum Option menu()
{

}
