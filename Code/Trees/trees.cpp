#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
};

void inorder(Node *root) //LDR
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteDeepest(Node *root, Node *d_node)
{
    queue<Node *> q;
    q.push(root);
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == d_node)
        {
            temp = NULL;
            delete (d_node);
            return;
        }
    }
}

Node *deletion(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    queue<Node *> q;
    q.push(root);
    Node *temp;
    Node *key_node = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            key_node = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    if (key_node != NULL)
    {
        int x = temp->data;
        deleteDeepest(root, temp);
        key_node->data = x;
    }
}

int main()
{
    Node *root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    inorder(root);
}