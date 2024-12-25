#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void print_List(struct Node * ptr){
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}
int main(){
    //Nodes of linekedList creation
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *n1=(struct Node *)malloc(sizeof(struct Node));
    struct Node *n2=(struct Node *)malloc(sizeof(struct Node));
    struct Node *n3=(struct Node *)malloc(sizeof(struct Node));
    struct Node *n4=(struct Node *)malloc(sizeof(struct Node));

    //value add to head and pointed to node n1
    head->data=1;
    head->next=n1;

    //value add to n1 and pointed to node n2
    n1->data=2;
    n1->next=n2;

    //value add to n2 and pointed to node n3
    n2->data=3;
    n2->next=n3;

    //value add to n3 and pointed to node n4
    n3->data=4;
    n3->next=n4;

    //value add to n4 and pointed to NULL
    n4->data=5;
    n4->next=NULL;

    //Printing linkedlist
    print_List(head);

    return 0;

}