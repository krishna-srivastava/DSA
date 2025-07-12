// using  circular queue........
#include<iostream>
#include <cstdlib>  
using namespace std;

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *q){
    return (q->f==-1 && q->r==-1);
}

int isfull(struct queue *q){
    return ((q->r+1)%q->size == q->f);
}

void enqueueFront(struct queue *q,int data){
    if(isfull(q)){
        cout<<"queue is full!"<<endl;
    }else if(q->f==-1 && q->r==-1){
        q->f=q->r=0;
        q->arr[q->f]=data;
    }else if(q->f==0){
        q->f=q->size-1;
        q->arr[q->f]=data;
    }else{
        q->f--;
        q->arr[q->f]=data;
    }
}

void enqueueRear(struct queue *q,int data){
    if(isfull(q)){
        cout<<"queue is full!"<<endl;
    }else if(q->f==-1 && q->r==-1){
        q->f=q->r=0;
        q->arr[q->r]=data;
    }else if(q->r==q->size-1){
        q->r=0;
        q->arr[q->r]=data;
    }else{
        q->r++;
        q->arr[q->r]=data;
    }
}

int dequeueFront(struct queue *q){
    int a=-1;
    if(isempty(q)){
        cout<<"queue is empty!"<<endl;
    }else if(q->f == q->r){
        a=q->arr[q->f];
        q->f=q->r=-1;
        return a;
    }else if(q->f==q->size-1){
        a=q->arr[q->f];
        q->f=0;
        return a;
    }else{
        a=q->arr[q->f];
        q->f++;
        return a;
    }
}

int dequeueRear(struct queue *q){
    int a=-1;
    if(isempty(q)){
        cout<<"queue is empty!"<<endl;
    }else if(q->f == q->r){
        a=q->arr[q->r];
        q->f=q->r=-1;
        return a;
    }else if(q->r==0){
        a=q->arr[q->r];
        q->r=q->size-1;
        return a;
    }else{
        a=q->arr[q->r];
        q->r--;
        return a;
    }
}

void display(struct queue *q){
    if(isempty(q)){
        cout<<"queue is empty!"<<endl;
    }else{
        int i=q->f;
        while(i != q->r){
            cout<<q->arr[i]<<" ";
            i=(i+1)%q->size;
        }
        cout<<q->arr[q->r]<<endl;
    }
}

int main(){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));  

    enqueueFront(q,1);
    enqueueFront(q,2);
    enqueueRear(q,4);
    enqueueRear(q,7);
    enqueueRear(q,12);
    display(q);

    dequeueFront(q);
    dequeueFront(q);
    dequeueRear(q);
    display(q);
    return 0;
};