#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// deleting first node
struct Node *deleteFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return NULL;
    }
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}
// deleting at index
struct Node *deleteIndex(struct Node *head, int index)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    struct Node *p = head, *q;
    if (index == 0)
    {
        head = head->next;
        free(p);
        return head;
    }
    for (int i = 1; i < index; i++)
    {
        if (p == NULL || p->next == NULL)
        {
            printf("Index out of bound.\n");
            return head;
        }
        p = p->next;
    }
    q = p->next;
    if (q == NULL)
    {
        printf("Index out of range\n");
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}
// delete at end
struct Node *deleteEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Node *p = head, *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
// print
void print_List(struct Node *ptr)
{
    if (ptr = NULL)
    {
        printf("List is empty\n");
        return NULL;
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

    head = deleteFirst(head);
    print_List(head);

    head = deleteIndex(head, 3);
    print_List(head);

    deleteEnd(head);
    print_List(head);

    return 0;
}