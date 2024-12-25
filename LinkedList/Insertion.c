#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void printlist(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// insert at beginnig
struct Node *insertBeg(struct Node *head, int d)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = d;
    n->next = head;
    return n;
}
// insert at index
void insertAt(struct Node *head, int data, int index)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    struct Node *p = head;
    for (int i = 0; i <= index; i++)
    {
        if (p == NULL)
        {
            printf("Index out of range.\n");
            return;
        }
        if (i == index - 1)
        {
            n->next = p->next;
            p->next = n;
        }
        p = p->next;
    }
}
// insert at end
void insertEnd(struct Node *head, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    if (head == NULL)
    {
        head = n;
        return;
    }
    struct Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = n;
    n->next = NULL;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tail = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = n1;

    n1->data = 2;
    n1->next = n2;

    n2->data = 3;
    n2->next = tail;

    tail->data = 4;
    tail->next = NULL;

    printlist(head);

    head = insertBeg(head, 0);
    printlist(head);

    // can't insert at index 0
    insertAt(head, 100, 5);
    printlist(head);
    // printf("%d",head->data);
    insertEnd(head, 101);
    printlist(head);

    return 0;
}