/*
 * 程序调试：单向链表
 */

#include <stdio.h>
#include <stdlib.h>

struct s_list
{
    int data;
    struct s_list *next;
};

// 传进去的是 s_list * 类型，这就导致作为实参的指针指向的地址不会改变
void create_list(struct s_list **headp, int *p);

int main(void)
{
    struct s_list *head = NULL, *p;
    int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    create_list(&head, s);
    p = head;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}

void create_list(struct s_list **headp, int *p)
{
    struct s_list *loc_head = NULL, *tail;
    if (p[0] == 0);
    else
    {
        loc_head = (struct s_list *) malloc(sizeof(struct s_list));
        loc_head->data = *p++;
        tail = loc_head;
        while (*p)
        {
            tail->next = (struct s_list *) malloc(sizeof(struct s_list));
            tail = tail->next;
            tail->data = *p++;
        }
        tail->next = NULL;
    }
    *headp = loc_head;
}
