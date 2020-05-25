#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void BToDll(Node* root, Node** head_ref)
{
    if(root == NULL)
        return;
    
    BToDll(root->right, head_ref);

    root->right = *head_ref;

    if(*head_ref != NULL)
        (*head_ref)->left = root;

    *head_ref = root;

    BToDll(root->left, head_ref);
}

void printList(Node* head)
{
    cout<<"Extracted double linked list  is "<<endl;
    while(head)
    {
        cout<<head->data<<" ";
        head = head->right;
    }
}

int main()
{
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->left->left->left = newNode(0); 
    root->left->left->right = newNode(2); 
    root->right->right->left = newNode(7); 
    root->right->right->right = newNode(9); 

    Node* head = NULL;
    BToDll(root, &head);
    printList(head);
}