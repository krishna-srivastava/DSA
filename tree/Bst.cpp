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

bool isBST(struct node* root, struct node* minNode = NULL, struct node* maxNode = NULL) {
    if (root == NULL) {
        return true;
    }
         
    if (maxNode != NULL && root->data >= maxNode->data) {
        return false;
    }
    if (minNode != NULL && root->data <= minNode->data) {
        return false;
    }
    
    return isBST(root->left, minNode, root) && 
           isBST(root->right, root, maxNode);
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

    if (isBST(root)) {
        cout << "The tree is a Binary Search Tree." << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree." << endl;
    };
    return 0;
}; 