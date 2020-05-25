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

void levelOrder(BstNode *head)
{
    if (head == NULL)
        return;
    queue<BstNode *> q;
    q.push(head);
    while (!q.empty())
    {
        BstNode *p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->left != NULL)
            q.push(p->left);
        if (p->right != NULL)
            q.push(p->right);
    }
}

void zigZag(BstNode *head)
{
    if (!head)
        return;
    stack<BstNode *> currentLevel;
    stack<BstNode *> nextLevel;

    currentLevel.push(head);
    bool leftorright = true;
    while (!currentLevel.empty())
    {
        BstNode *temp = currentLevel.top();
        currentLevel.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (leftorright)
            {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }
        if (currentLevel.empty())
        {
            leftorright = !leftorright;
            swap(currentLevel, nextLevel);
        }
    }
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
    levelOrder(root);
    cout << endl;
    zigZag(root);
}