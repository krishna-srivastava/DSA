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

void insert(node* root, int key){
    struct node* prev=NULL;
    while (root != NULL){
        prev=root;
        if(root->data == key){
            return;
        }else if(root->data > key){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    struct node* n = createnode(key);
    if(prev->data > key){
        prev->left=n;
    }else{
        prev->right=n;
    }
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    struct node* root = createnode(5);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(4);
    
    root->left = p1;
    root->right = p2;

    p1->left=p3;
    p1->right = p4;

    inorder(root);
    insert(root,12);
    inorder(root);
    return 0;
}; 