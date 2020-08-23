// AVL tree is a self-balancing Binary Search Tree (BST) 
// where the difference between heights of left and right 
// subtrees cannot be more than one for all nodes.

// Preorder traversal of the constructed AVL tree is
// 30 20 10 25 40 50

// Time Complexity: The rotation operations (left and right rotate) 
// take constant time as only a few pointers are being changed there. 
// Updating the height and getting the balance factor also takes 
// constant time. So the time complexity of AVL insert remains same 
// as BST insert which is O(h) where h is the height of the tree. 
// Since AVL tree is balanced, the height is O(Logn). 
// So time complexity of AVL insert is O(Logn).

// The AVL trees are more balanced compared to Red-Black Trees, but 
// they may cause more rotations during insertion and deletion.
// So if your application involves many frequent insertions and 
// deletions, then Red Black trees should be preferred. And if 
// the insertions and deletions are less frequent and search is 
// the more frequent operation, 
// then AVL tree should be preferred over Red Black Tree.

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* a)
{
    if(a == NULL)
        return 0;
    return a->height;
}

Node* newNode(int data)
{
    Node* newN = new Node;
    newN->data = data;
    newN->left = NULL;
    newN->right = NULL;
    newN->height = 1;
    return newN;
}

int getBalance(Node* a)
{
    if(a == NULL)
        return 0;
    return height(a->left) - height(a->right);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* y)
{
    Node* x = y->right;
    Node* z = x->left;

    x->left = y;
    y->right = z;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* minVal(Node* root)
{
    if(root == NULL)
        return NULL;
    while(root->left != NULL)
        root = root->Left;
    return root;
}

// time complexity of AVL delete is O(Log n).
Node* deleteNode(Node* root, int data)
{
    if(root == NULL)
        return NULL;
    
    if(root->data > data)
        root->left = deleteNode(root->left, data);
    else if(root->data < data)
        root->right = deleteNode(root->right, data);
    else
    {
        if(root->left == NULL || root->right == NULL)
        {
            Node* temp = root->left ? root->left : root->right;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            
            free(temp);
        }
        else
        {
            Node* temp = minVal(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if(root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // left left case
    if(balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // left right case
    if(balance > 1 && getBalnce(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right right case
    if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    
    // right left case
    if(balance < -1 && getBalance() > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* insert(Node* root, int data)
{
    if(root == NULL)
        return newNode(data);

    if(root->data > data)
        root->left = insert(root->left, data);
    else if(root->data < data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // left left case
    if(balance > 1 && data < root->left->data)
        return rightRotate(root);

    // right right case
    if(balance < -1 && data > root->right->data)
        return leftRotate(root);
    
    // left right case
    if(balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right left case
    if(balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node* root = NULL;
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25); 
    preOrder(root);
}