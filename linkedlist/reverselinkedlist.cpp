#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    node *next;
};

struct node* reverselinkedlist(node *head){
    struct node* prev=NULL;
    struct node* current=head;
    struct node* next=NULL;

    while(current != NULL){
    next=current->next;
    current->next=prev; 
    prev = current;
    current=next;
    }
    return prev;
}

void printer(node* head){
    cout<<endl;
    cout<<"element: ";
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    node *head;
    node *second;
    node *third;
    node *fourth;

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

    head=reverselinkedlist(head);
    printer(head);
    
    return 0;
};