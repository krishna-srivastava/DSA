#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*next;
    struct node*prev;
};

struct node* insertAtFirst(struct node* head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    head=ptr;
    return head;
}

struct node* insertAtIndex(struct node* head, int data, int index) {
    if (index < 0) return head;
    struct node* ptr = (struct node*) malloc(sizeof(struct node)); 
    ptr->data = data;

    if (index == 0) {
        insertAtFirst(head,data);
    }

    struct node* p = head;
    for (int i = 0; p != NULL && i < index - 1; i++) {
        p = p->next;
    }
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
}

struct node* insertAtEnd(struct node* head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    while(p->next != NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->prev=p;
}

struct node* deleteAtFirst(struct node* head){
    struct node* ptr=head;
    head=head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

struct node *deleteAtindex(struct node* head,int index){
    struct node* p=head;
    struct node* q=head->next;
    int i=0;
    if(index == 0){
       return deleteAtFirst(head);
    }

    while (i != index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    q->prev = p;
    free(q);
    return head;
}

struct node* deleteAtEnd(struct node *head){
    struct node* p = head;
    struct node* q = head->next;
    while (q->next != NULL) {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
};
 
void traversal(struct node* ptr){
    cout<<endl;
    cout<<"element: ";
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=44;
    head->prev=NULL;
    head->next=second;

    second->data=96;
    second->prev=head;
    second->next=third;

    third->data=6;
    third->prev=second;
    third->next=fourth;

    fourth->data=11;
    fourth->prev=third;
    fourth->next=NULL;

    // head=insertAtFirst(head,63);
    // head=insertAtFirst(head,66);

    // insertAtIndex(head,21,0);

    // insertAtEnd(head,34);

    // head=deleteAtFirst(head);
    deleteAtindex(head,0);
    // deleteAtEnd(head);

    traversal(head);

    return 0;
};