#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* makeNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if(root == NULL)
        return makeNode(data);
    if(root->data > data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

Node* search(Node* root, int x)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == x)
        return root;

    if(root->data > x)
        return search(root->left, x);
    else
        return search(root->right, x);
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* minVal(Node* root)
{
    if(root == NULL)
        return NULL;
    
    while(root && root->left)
        root = root->left;
    
    return root;
    
}

Node *deleteNode(Node *root,  int X)
{
    if(root == NULL)
        return NULL;
    
    if(root->data > X)
        root->left = deleteNode(root->left, X);
    else if(root->data < X)
        root->right = deleteNode(root->right, X);
    else
    {
        if(root->left  == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = minVal(root->right);
        
        root->data = temp->data;
        
        root->right = deleteNode(root->right, temp->data); 
    }
    return root;
}

int main()
{
    Node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 

    inorder(root);
    cout<<endl;
    Node* s = search(root, 80);
    if(s != NULL)
        cout<<s->data<<endl;

}