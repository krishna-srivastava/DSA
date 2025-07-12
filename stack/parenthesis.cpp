//parenthesis checking using stack 
#include<iostream>
using namespace std;

struct stack{
    int size;
    int top;
    char *arr;
};

int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return -1;
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

int push(struct stack * ptr,char data){
    if(isfull(ptr)){
        cout<<"stack overflow!"<<endl;
        return 1;
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

char pop(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack underflow!"<<endl;
        return -1;
    }else{
        char val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return val;
    }
}

int parenthesis(char *exp,int size){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size=size;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '('){
            push(sp,exp[i]);
        }
        else if(exp[i] == ')'){
            if(isempty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if(isempty(sp)){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char exp[]="11*(1+2)-(2+2*3)+8(1)";
    int size=sizeof(exp)/sizeof(exp[0]);
    if(parenthesis(exp,size)){
        cout<<"balanced expression!"<<endl;
    }else{
        cout<<"unbalanced expression!"<<endl;
    }

    return 0;
};