#include<iostream>
using namespace std;
    
struct node {
    int data;
    struct node* next;
};
 
struct node* reverseCircularLinkedlist(node* head) {
    struct node* current = head->next;
    struct node* prev = head;
    struct node* next = current->next;

    while (current != head) {
        current->next = prev;
        prev = current;
        current = next;
        next = current->next;
    }
    head->next = prev;
    return prev;
}

void traversal(struct node* head) {
    struct node* ptr = head;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

int main() {
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *tail;

    head = new node();
    second = new node();
    third = new node();
    tail = new node();

    head->data = 69;
    head->next = second;

    second->data = 96;
    second->next = third;

    third->data = 6;
    third->next = tail;

    tail->data = 11;
    tail->next = head;

    head = reverseCircularLinkedlist(head);
    traversal(head);

    return 0;
}
