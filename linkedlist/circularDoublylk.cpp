#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
}; 

struct node* traversal(struct node* ptr){
    cout << "Element: ";
    struct node* start = ptr;  
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while(ptr != start); 
    cout << endl;
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

    head->data=44;
    head->prev=fourth;
    head->next=second;

    second->data=96;
    second->prev=head;
    second->next=third;

    third->data=6;
    third->prev=second;
    third->next=fourth;

    fourth->data=11;
    fourth->prev=third;
    fourth->next=head;

    traversal(head);
    return 0;
};