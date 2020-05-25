#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void printTrees(Node *head) // level order traversal
{
    Node *temp = head;
    queue<Node *> q;
    q.push(temp);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->left != NULL)
            q.push(p->left);
        if (p->right != NULL)
            q.push(p->right);
    }
}

int maxDepth(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
        return 0;
    return max(maxDepth(temp->left), maxDepth(temp->right)) + 1;
}

void mirror(Node *head) // mirror the Binary tree
{
    if (head == NULL)
        return;
    mirror(head->left);
    mirror(head->right);
    Node *temp = head->left;
    head->left = head->right;
    head->right = temp;
}

void sumOfLeakNodes(Node *head, int *sum) // method 1
{
    Node *temp = head;
    if (temp == NULL)
        return;
    if (temp->left == NULL && temp->right == NULL)
        *sum += temp->data;
    sumOfLeakNodes(temp->left, sum);
    sumOfLeakNodes(temp->right, sum);
}

int sumLeaf(Node *root) // method 2
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    int sum = 0;
    sum += sumLeaf(root->left) + sumLeaf(root->right);
    return sum;
}

int main()
{
    Node *head = newNode(1);
    head->left = newNode(2);
    head->left->left = newNode(4);
    head->left->right = newNode(5);
    head->right = newNode(3);
    head->right->right = newNode(7);
    head->right->left = newNode(6);
    head->right->left->right = newNode(8);
    printTrees(head);
    cout << endl;
    cout << "height : " << maxDepth(head);
    mirror(head);
    cout << endl;
    int sum = 0;
    sumOfLeakNodes(head, &sum);
    cout << sum << endl;
    printTrees(head);
    cout << endl;
    sum = 0;
    sumOfLeakNodes(head, &sum);
    cout << sum;
}
