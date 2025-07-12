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

struct node *seaching(node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }else if(root->data > key){
        return seaching(root->left,key);
    }else{
        return seaching(root->right,key); 
    }
}

int main(){
    struct node* root = createnode(5);
    struct node* p1 = createnode(2);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(4);
    
    root->left = p1;
    root->right = p2;

    p1->left=p3;
    p1->right = p4;

    struct node*n=seaching(root,4);
    if(n != NULL){
        cout<<"found: "<<n->data<<endl;
    }else{
        cout<<"not found"<<endl;
    }
    return 0;
}; 