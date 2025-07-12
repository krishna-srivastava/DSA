#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

int isempty(struct node *top){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct node *top){
    struct node* p= (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }else{
        return 0;
    }
}

struct node* push(struct node *top,int data){
    if(isfull(top)){
        cout<<"stack overflow!"<<endl;
    }else{
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }
}

int pop(struct node**top){
    if(isempty(*top)){
        cout<<"stack underflow!"<<endl;
    }else{
        struct node * n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}

int peek(struct node * top,int pos){
    struct node * ptr=top;
    for(int i=0; (i<pos && ptr!=NULL); i++){
        ptr=ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;
    }else{
        return -1;
    }
}

int stacktop(struct node* top){
    return top->data;
}

int stackbottom(struct node * top){
    struct node * ptr=top;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    return ptr->data;
}

void traversal(struct node* top){
    cout<<"element: ";
    while(top != NULL){
        cout<<top->data<<" ";
        top=top->next;
    }
    cout<<endl;
}

int main(){
    struct node*top=NULL;
    top=push(top,28);
    top=push(top,8);
    top=push(top,18);
    top=push(top,15);
    top=push(top,7);

    traversal(top);

    // cout<<"this element is pop from stack: "<<pop(&top)<<endl;
    // traversal(top);

    cout<<"the value at postion 2 (0-based index) is: "<<peek(top,2)<<endl;
    cout<<"This is the top element of the stack: "<<stacktop(top)<<endl;
    cout<<"This is the bottom element of the stack: "<<stackbottom(top)<<endl;
    return 0;
};