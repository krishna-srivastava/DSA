#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertAtFirst(Node* head, int data) {
    Node* ptr = new Node();  
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

Node* insertAtIndex(Node* head, int data, int index) {
    Node* ptr = new Node(); 
    Node* p = head;
    int i = 0;

    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head; 
}

Node* insertAtEnd(Node* head, int data) {
    Node* ptr = new Node();  
    Node* p = head;
    ptr->data = data;
    ptr->next = NULL;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

void printer(Node* ptr) {
    cout << endl;
    cout << "Elements: ";
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node();  
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 69;
    head->next = second;

    second->data = 96;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    printer(head);

    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 11);
    head = insertAtFirst(head, 77);

    head = insertAtIndex(head, 100, 2);
    head = insertAtIndex(head, 100, 5);

    head = insertAtEnd(head, 200);
    head = insertAtEnd(head, 111);

    printer(head);

    return 0;
}
