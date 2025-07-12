//stack using array........
#include<iostream>
#include<stdlib.h>
using namespace std;

struct stack{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}

int push(struct stack * ptr,int data){
    if(isfull(ptr)){
        cout<<"stack overflow!"<<endl;
        return 1;
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

int pop(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack underflow!"<<endl;
        return -1;
    }else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack underflow!"<<endl;
        return -1;
    }else{
        return (ptr->arr[ptr->top]);
    }
}

int top(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack underflow!"<<endl;
        return -1;
    }else{
        return (ptr->arr[ptr->top]);
    }
}

int bottom(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack underflow!"<<endl;
        return -1;
    }else{
        return ptr->arr[0];
    }
}

int display(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack underflow!"<<endl;
        return -1;
    }else{
        for(int i=0; i<=ptr->top; i++){
            cout<<ptr->arr[i]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));
     
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,60);
    push(s,70);
    push(s,80);
    push(s,90);
    push(s,100);

    cout<<"the stack data: ";
    display(s);

    cout<<"this value is pop "<<pop(s)<<endl;
    cout<<"this value is pop "<<pop(s)<<endl;

    cout<<"the stack data after pop: ";
    display(s);

    cout<<"the peak value of the stack is: "<<peek(s)<<endl;

    cout<<"the top value of the stack is: "<<top(s)<<endl;
    cout<<"the bottom value of the stack is: "<<bottom(s)<<endl;

    return 0;
};