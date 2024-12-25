#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAny(struct Node *head, int data, int index)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    if (index == 0)
    {
        n->next = head;
        return n;
    }
    else
    {
        struct Node *p = head;
        for (int i = 0; i < index; i++)
        {
            if (p == NULL)
            {
                printf("index out of range\n");
                free(n);
                return head;
            }
            else if (i == index - 1)
            {
                n->next = p->next;
                p->next = n;
            }
            p = p->next;
        }
    }
    return head;
}
void print_List(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = n1;

    n1->data = 2;
    n1->next = n2;

    n2->data = 3;
    n2->next = n3;

    n3->data = 4;
    n3->next = n4;

    n4->data = 5;
    n4->next = NULL;

    print_List(head);

    // insert at any location
    head = insertAny(head, 0, 0);
    print_List(head);

    head = insertAny(head, 6, 6);
    print_List(head);

    head = insertAny(head, 7, 7);
    print_List(head);

    return 0;
}