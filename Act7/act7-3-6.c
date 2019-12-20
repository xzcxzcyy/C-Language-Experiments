/*
 * 逆波兰表达式
 * （不支持负数）
 * （除法为整数除法）
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE sizeof(struct Node)

struct Node;
typedef struct Node *PN;

struct Node
{
    int x;
    PN next;
};

void push_front(PN head, int data);
int pop_front(PN head);

int main()
{
    enum State
    {
        init, num
    };
    enum State cur = init;

    PN stack = malloc(SIZE);
    stack->next = NULL;
    char ch;
    int n = 0;
    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == ')')
        {
            continue;
        }
        switch (cur)
        {
            case init:
                if (ch >= '0' && ch <= '9')
                {
                    cur = num;
                    n = ch - '0';
                }
                else if (ch == ' ')
                {
                    continue;
                }
                else if (ch == '+')
                {
                    int opr2 = pop_front(stack);
                    int opr1 = pop_front(stack);
                    push_front(stack, opr1 + opr2);
                }
                else if (ch == '-')
                {
                    int opr2 = pop_front(stack);
                    int opr1 = pop_front(stack);
                    push_front(stack, opr1 - opr2);
                }
                else if (ch == '*')
                {
                    int opr2 = pop_front(stack);
                    int opr1 = pop_front(stack);
                    push_front(stack, opr1 * opr2);
                }
                else if (ch == '/')
                {
                    int opr2 = pop_front(stack);
                    int opr1 = pop_front(stack);
                    push_front(stack, opr1 / opr2);
                }
                break;

            case num:
                if (ch >= '0' && ch <= '9')
                {
                    n = n * 10 + (ch - '0');
                }
                else if (ch == ' ')
                {
                    push_front(stack, n);
                    cur = init;
                }
                break;
        }
    }
    printf("%d", pop_front(stack));
    free(stack);
    return 0;
}

void push_front(PN head, int data)
{
    PN nnode = malloc(SIZE);
    nnode->x = data;
    nnode->next = head->next;
    head->next = nnode;
}

int pop_front(PN head)
{
    assert(head->next != NULL);
    int res = head->next->x;
    PN toBeDel = head->next;
    head->next = head->next->next;
    free(toBeDel);
    return res;
}
