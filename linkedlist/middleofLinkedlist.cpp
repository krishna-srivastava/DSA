#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

void findMiddle(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        
        fast = fast->next->next;
    }
    cout << "The middle element is: " << slow->data << endl;
}

void printer(node* ptr) {
    cout << endl;
    cout << "List: ";
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    node *head;
    node *second;
    node *third;
    node *fourth;

    head = new node();
    second = new node();
    third = new node();
    fourth = new node();

    head->data = 69;
    head->next = second;

    second->data = 96;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    printer(head);
    findMiddle(head);
    return 0;
}
