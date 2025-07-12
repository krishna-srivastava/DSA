#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    node *next;
};

//delete at first...
struct node* deleteAtfirst(node* head){
    node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

//delete according to index......
struct node* deleteAtindex(node* head,int index){
    node * p=head;
    int i=0;
    while(i != index-1){
        p=p->next;
        i++;
    }
    node * q = p->next;
    p->next=q->next;
    free(q);
}

//delete at End...
struct node* deleteAtEnd(node* head){
    node * p=head;
    node * q=head->next;
    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}

void printer(node* ptr){
    cout<<endl;
    cout<<"element: ";
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=new node();
    second=new node();
    third=new node();
    fourth=new node();

    head->data=69;
    head->next=second;

    second->data=96;
    second->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=11;
    fourth->next=NULL;

    printer(head);
    // head=deleteAtfirst(head); //delete at first...

    // deleteAtindex(head,2);  //delete accordind to index......

    // deleteAtEnd(head);  //delete at End....
    // printer(head);

    return 0;
};