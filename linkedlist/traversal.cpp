#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    node *next;
};

void printer(node* ptr){
    cout<<endl;
    cout<<"element: ";
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
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

    printer(head);
    return 0;
};