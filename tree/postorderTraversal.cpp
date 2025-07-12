#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node* n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    struct node* root = createnode(2);
    struct node* p1 = createnode(1);
    struct node* p2 = createnode(9);
    struct node* p3 = createnode(2);
    struct node* p4 = createnode(2);
    
    root->left = p1;
    root->right = p2;

    p1->left=p3;
    p1->right = p4;

    postorder(root);
    return 0;
}; 