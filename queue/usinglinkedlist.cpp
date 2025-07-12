#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *f= NULL;
struct node *r= NULL;

int isempty(struct node* f){
    if(f==NULL){
        return 1;
    }
    return 0;
}

void enqueue(int val){
    struct node*ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        cout<<"The queue is full!"<<endl;
    }else{
        ptr->data=val;
        ptr->next=NULL;

        if(f==NULL){
            f=r=ptr;
        }else{
            r->next=ptr;
            r=ptr;
        }
    }
}

int dequeue(){
    int val=-1;
    struct node*ptr = f;
    if(isempty(f)){
        cout<<"queue is epmty!"<<endl;
    }else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

void traversal(struct node *f){
    cout<<"Queue: ";
    while(f != NULL){
        cout<<f->data<<" ";
        f=f->next;
    }
    cout<<endl;
}

int main(){
    enqueue(56);
    enqueue(12);
    enqueue(12);
    enqueue(12);
    enqueue(22);
    enqueue(52);
    enqueue(2);
    traversal(f);

    dequeue();
    dequeue();
    traversal(f);

    return 0;
};