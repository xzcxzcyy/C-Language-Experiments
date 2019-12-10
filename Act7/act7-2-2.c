/*
 * 程序修改：栈链表
 */

#include <stdio.h>
#include <stdlib.h>

struct s_list
{
    int data;
    struct s_list *next;
};

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
    if (p[0])
    {
        loc_head = (struct s_list *) malloc(sizeof(struct s_list));
        loc_head->data = *p++;
        tail = loc_head;
        tail->next = NULL;
        while (*p)
        {
            struct s_list *previous = loc_head;
            loc_head = (struct s_list *) malloc(sizeof(struct s_list));
            loc_head->next = previous;
            loc_head->data = *p++;
        }
    }
    *headp = loc_head;
}
