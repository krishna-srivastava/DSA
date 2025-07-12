#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* insertAtfirst(struct node* head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    struct node *p=head;
    while(p->next != head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
}

struct node *insertAtindex(struct node* head,int data,int index){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;

    while(i != index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
}

struct node* insertAtEnd(struct node* head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    struct node *p=head;
    while(p->next != head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
}

struct node * deleteatfirst(struct node *head){
    struct node* p=head;
    struct node* q=head->next;
    while(q->next != head){
        q=q->next;
    }
    q->next=p->next;
    head=head->next;
    free(p);
    return head;
}

struct node * deleteatindex(struct node *head,int index){
    struct node* p=head;
    struct node* q=head->next;
    int i=0;
    while(i != index-1){
        q=q->next;
        p=p->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node* traversal(struct node* head){
    struct node* ptr=head;
    do{
    cout<<""<<ptr->data<<" ";
    ptr=ptr->next;
    }while(ptr!= head);
    cout<<endl;
}


int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=69;
    head->next=second;

    second->data=96;
    second->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=11;
    fourth->next=head;

    // traversal(head);

    // head=insertAtfirst(head,22);
    // head=insertAtfirst(head,45);

    // insertAtindex(head,90,3);

    // insertAtEnd(head,78);
    // insertAtEnd(head,13);
    // traversal(head);

    // head=deleteatfirst(head);
    deleteatindex(head,2);
    traversal(head);
    return 0;
};