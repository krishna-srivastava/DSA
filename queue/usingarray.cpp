#include <iostream>
#include <cstdlib>  // For malloc
using namespace std;

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *q) {
    return (q->f == -1 || q->f > q->r);
}

int isfull(struct queue *q) {
    return (q->r == q->size - 1);
}

void enqueue(struct queue *q, int val) {
    if (isfull(q)) {
        cout << "Queue overflow!" << endl;
    } else {
        if (q->f == -1) {
            q->f = 0;
        }
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (isempty(q)) {
        cout << "Queue underflow!" << endl;
    } else {
        a = q->arr[q->f];
        q->f++;
        if (q->f > q->r) { 
            q->f = q->r = -1;
        }
    }
    return a;
}


void traversal(struct queue *q) {
    if (isempty(q)) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue: ";
        for (int i = q->f; i <= q->r; i++) {
            cout << q->arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    enqueue(q, 21);
    enqueue(q, 1);
    enqueue(q, 34);
    enqueue(q, 55);
    enqueue(q, 95);

    traversal(q);

    cout << "Dequeued element: " << dequeue(q) << endl;
    cout << "Dequeued element: " << dequeue(q) << endl;

    traversal(q);

    free(q->arr);
    free(q);
    return 0;
}
