//infix to postfix........................
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct stack {
    int top;
    int size;
    char* arr;
};

int top(struct stack *ptr) {
    if(ptr->top == -1) {
        return -1;
    } else {
        return ptr->arr[ptr->top];
    }
}

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

void push(struct stack *ptr, char data) {
    if(isfull(ptr)) {
        cout << "Stack Overflow!" << endl;
    } else {
        ptr->arr[++ptr->top] = data;
    }
}

char pop(struct stack *ptr) {
    if(isempty(ptr)) {
        cout << "Stack Underflow!" << endl;
        return -1;
    } else {
        return ptr->arr[ptr->top--];
    }
}

int isoperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if(ch == '*' || ch == '/') return 3;
    if(ch == '+' || ch == '-') return 2;
    return 0;
}

char *infixtopostfix(char *infix) {
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    char *postfix = (char*)malloc(strlen(infix) * sizeof(char));
    int i = 0, j = 0;

    while(infix[i] != '\0') {
        if(!isoperator(infix[i])) { 
            postfix[j++] = infix[i++];
        } else {
            while(!isempty(sp) && precedence(infix[i]) <= precedence(top(sp))) {
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i++]);
        }
    }

    while(!isempty(sp)) {
        postfix[j++] = pop(sp);
    }
    postfix[j] = '\0';

    free(sp->arr);  
    free(sp);       
    return postfix;
}

int main() {
    char exp[] = "a+b*a/q";
    cout << "Postfix: " << infixtopostfix(exp) << endl;
    return 0;
}
