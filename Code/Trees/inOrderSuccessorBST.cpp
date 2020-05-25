#include <bits/stdc++.h>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

void Inorder(BstNode *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

BstNode *search(BstNode *root, int data)
{
    if (root == NULL)
        return NULL;
    if (data == root->data)
        return root;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

BstNode *minValue(BstNode *root)
{
    BstNode *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

BstNode *inOrderSuccessor(BstNode *root, BstNode *n)
{
    if (n->right != NULL)
        return minValue(n->right);
    BstNode *succ = NULL;
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

int main()
{
    BstNode *root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 22);
    root = Insert(root, 4);
    root = Insert(root, 12);
    root = Insert(root, 10);
    root = Insert(root, 14);
    Inorder(root);
    BstNode *temp = search(root, 4);
    cout << endl;
    BstNode *inOrder = inOrderSuccessor(root, temp);
    cout << inOrder->data << endl;
}