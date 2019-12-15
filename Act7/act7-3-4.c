/*
 * 高精度计算
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE sizeof(struct Node)

struct Node;
typedef struct Node *List;
typedef const struct Node *CList;

struct Node
{
    int d; //digit
    List next;
};

List read();
List add(CList a, CList b);
void print(CList l);

int main()
{
    List a = read(), b = read();
    List c = add(a, b);
    print(c);
    return 0;
}

// FILO List
List read()
{
    List head = malloc(SIZE);
    head->d = -1;
    head->next = NULL;
    char temp;
    while (temp = getchar(), temp != '\n' && temp != ' ')
    {
        List l = malloc(SIZE);
        l->d = temp - '0';
        l->next = head->next;
        head->next = l;
    }
    return head;
}

// ATTENTION HERE
// 传入的参数是从低位到高位存储，而计算的结果是从高位到低位存储
List add(CList a, CList b)
{
    List res_head = malloc(SIZE);
    res_head->d = -1;
    res_head->next = NULL;
    int buff = 0;
    CList i = a->next, j = b->next;
    while (i != NULL || j != NULL)
    {
        List l = malloc(SIZE);
        l->d = buff;
        if (i != NULL)
        {
            l->d += i->d;
            i = i->next;
        }
        if (j != NULL)
        {
            l->d += j->d;
            j = j->next;
        }
        buff = l->d / 10;
        l->d %= 10;
        l->next = res_head->next;
        res_head->next = l;
    }
    if (buff)
    {
        List l = malloc(SIZE);
        l->d = buff;
        l->next = res_head->next;
        res_head->next = l;
    }
    return res_head;
}

void print(CList l)
{
    CList p = l->next;
    while (p != NULL)
    {
        printf("%d", p->d);
        p = p->next;
    }
}
