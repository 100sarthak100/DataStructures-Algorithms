// Given a Binary Tree, find size of the Largest Independent Set(LIS) in it
// Size of the Largest Independent Set is 5


#include <bits/stdc++.h>
using namespace std;

// recursion
class node
{
    public:
    int data;
    node *left, *right;
};

node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int LISS(node *root)
{
    if(root == NULL)
        return 0;

    int size_excl = LISS(root->left) + LISS(root->right);

    int size_incl = 1;
    if(root->left)
        size_incl += LISS(root->left->left) +
                     LISS(root->left->right);

    if(root->right)
        size_incl += LISS(root->right->left) +
                     LISS(root->right->right);

    return max(size_incl, size_excl);
}

int main()
{
    node *root = newNode(20);  
    root->left = newNode(8);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);  
    root->right = newNode(22);  
    root->right->right = newNode(25);  
  
    cout << "Size of the Largest" 
         << " Independent Set is " 
         << LISS(root);  
  
    return 0; 
}

// dp

class node
{
    public:
    int data;
    int liss;
    node *left, *right;
};

node* newNode(int data)  
{  
    node* temp = new node();  
    temp->data = data;  
    temp->left = temp->right = NULL;  
    temp->liss = 0;  
    return temp;  
}  

int LISS(node * root)
{
    if(root == NULL)
        return 0;
    
    if(root->liss)
        return root->liss;

    if(root->left == NULL && root->right == NULL)
        return (root->liss = 1);

    int liss_excl = LISS(root->left) + LISS(root->right);

    int liss_incl = 1;
    if(root->left)
        liss_incl += LISS(root->left->left) + LISS(root->left->right);
    if(root->right)
        liss_incl += LISS(root->right->left) + LISS(root->right->right);
    root->liss = max(liss_incl, liss_excl);
    return root->liss;
}