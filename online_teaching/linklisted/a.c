#include<stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* pre;
} Node;

typedef struct List{
    Node *head;
    Node *tail;
} List;

Node *createNode(int data){
    Node *p = malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}

int main(){
    List list = {.head = NULL, .tail = NULL};
    list.head = createNode(1);
    list.tail = list.head;

    list.tail->next = createNode(2);
    list.tail->next->pre = list.tail;
    list.tail = list.tail->next;

    list.tail->next = createNode(3);
    list.tail->next->pre = list.tail;
    list.tail = list.tail->next;

    Node *p = createNode(0);
    p->next = list.head;
    list.head = p;

    Node *curr = list.head;
    while(curr != NULL){
        printf("%d", curr->data);
        curr = curr->next;
    }

    curr = list.head;
    while(curr->next->data != 2){
        curr = curr->next;
    }
    Node *del = curr->next;
    curr->next->next->pre = curr;
    curr->next = curr->next->next;
    free(del);

    curr = list.head;
    while(curr != NULL){
        printf("%d", curr->data);
        curr = curr->next;
    }
    return 0;
}