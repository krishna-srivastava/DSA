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

int main(){
    // Creating new nodes
    struct node* root = createnode(2);
    struct node* p1 = createnode(1);
    struct node* p2 = createnode(9);
    struct node* p3 = createnode(2);
    struct node* p4 = createnode(2);
    struct node* p5 = createnode(5);
    struct node* p6 = createnode(7);
    struct node* p7 = createnode(3);
    struct node* p8 = createnode(8);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    p3->left = p7;
    p4->right = p8;

    p5->left = p7;  

    /*graphical representation..

          2 
        /   \
       1      9
      / \    /  \
     2   2  5    7
        /      /
       8      3

    */

    return 0;
}
