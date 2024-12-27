#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
void printListForward(struct Node *head)
{
    if (head->next == head || head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct Node *p = head;
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(head)\n");
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tail = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 1;
    head->next = n1;

    n1->prev = head;
    n1->data = 2;
    n1->next = n2;

    n2->prev = n1;
    n2->data = 3;
    n2->next = tail;

    tail->prev = n2;
    tail->data = 4;
    tail->next = NULL;

    printListForward(head);
    return 0;
}