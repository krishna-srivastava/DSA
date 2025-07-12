#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node *createnode(int data)
{
    struct node *n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *findMin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    struct node *root = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 3);
    root = deleteNode(root, 5);
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
