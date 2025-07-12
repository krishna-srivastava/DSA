#include<iostream>
#include<cstdlib>  // Include for malloc and free
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

int main() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};  
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    cout << i << " ";  
    visited[i] = 1;
    enqueue(q, i);

    while (!isempty(q)) {
        node = dequeue(q);
        for (int j = 0; j < 7; j++) {  
            if (a[node][j] == 1 && visited[j] == 0) {  
                cout << j << " ";
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    free(q->arr);
    free(q);

    return 0;
}
