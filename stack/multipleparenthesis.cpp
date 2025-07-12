#include <iostream>
#include <cstdlib>
using namespace std;

struct stack {
    int size;
    int top;
    char *arr;
};

int isempty(struct stack *ptr) {
    return ptr->top == -1;
}

int isfull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

char stackTop(struct stack *ptr) {
    if (isempty(ptr)) {
        cout << "stack underflow!" << endl;
        return -1;
    } else {
        return ptr->arr[ptr->top];
    }
}

int push(struct stack *ptr, char data) {
    if (isfull(ptr)) {
        cout << "stack overflow!" << endl;
        return 1;
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        return 0;
    }
}

char pop(struct stack *ptr) {
    if (isempty(ptr)) {
        cout << "stack underflow!" << endl;
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesis(char *exp, int size) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = size;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(sp, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isempty(sp)) return 0;
            if ((exp[i] == ')' && stackTop(sp) != '(') ||
                (exp[i] == '}' && stackTop(sp) != '{') ||
                (exp[i] == ']' && stackTop(sp) != '[')) {
                return 0;
            }
            pop(sp);
        }
    }

    int result = isempty(sp);
    free(sp->arr);
    free(sp);
    return result;
}

int main() {
    char exp[] = "([{}])";
    int size = sizeof(exp) / sizeof(exp[0]);

    if (parenthesis(exp, size)) {
        cout << "Balanced expression!" << endl;
    } else {
        cout << "Unbalanced expression!" << endl;
    }

    return 0;
}
