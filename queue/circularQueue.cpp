#include<iostream>
#include<cstdlib>
using namespace std;

struct circularqueue {
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct circularqueue *q) {
    return (q->f == -1 && q->r==-1);
}

int isfull(struct circularqueue *q) {
    return ((q->r + 1) % q->size == q->f);
}

void enqueue(struct circularqueue *q, int val) {
    if (isfull(q)) {
        cout << "Queue overflow!" << endl;
    } else if (isempty(q)) {
        q->f = q->r = 0;
        q->arr[q->r] = val;
    } else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularqueue *q) {
    int a = -1;
    if (isempty(q)) {
        cout << "Queue underflow!" << endl;
    } else if (q->f == q->r) {
        a = q->arr[q->f];
        q->f = q->r = -1;
    } else {
        a = q->arr[q->f];
        q->f = (q->f + 1) % q->size;
    }
    return a;
}

void traversal(struct circularqueue *q) {
    if (isempty(q)) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue: ";
        int i = q->f;
        while (i != q->r) {
            cout << q->arr[i] << " ";
            i = (i + 1) % q->size;
        }
        cout << q->arr[q->r] << endl;  
    }
}

int main() {
    struct circularqueue *q = (struct circularqueue*)malloc(sizeof(struct circularqueue));
    q->size = 4;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));  

    enqueue(q, 21);
    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 34);

    traversal(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 2);
    enqueue(q, 1);
    enqueue(q, 4);
    enqueue(q, 1);

    traversal(q);
    return 0;
}
