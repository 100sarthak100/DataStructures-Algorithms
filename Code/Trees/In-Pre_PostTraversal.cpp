#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long data;
    Node *left;
    Node *right;
};

Node *makeNode(long data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node *head, int data)
{
    queue<Node *> q;
    q.push(head);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        if (p->left == NULL)
        {
            p->left = makeNode(data);
            break;
        }
        else
            q.push(p->left);
        if (p->right == NULL)
        {
            p->right = makeNode(data);
            break;
        }
        else
            q.push(p->right);
    }
}

void levelOrder(Node *head)
{
    if (head == NULL)
        return;
    queue<Node *> q;
    q.push(head);
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

// recursion
void inOrder(Node *head) //LDR (non decreasing order)
{
    if (head == NULL)
        return;
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

void inOrderIterative(Node *head)
{
    stack<Node *> st;
    Node *curr = head;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

// recusrsion
void preOrder(Node *head) // DLR (to get prefix expression of an expression tree)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

void preOrderIterative(Node *head) // time complexity O(N);
{
    if (head == NULL)
        return;
    stack<Node *> st;
    Node *curr = head;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            if (curr->right)
                st.push(curr->right);
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

// recursion
void postOrder(Node *head) //LRD (used to delete the tree)
{
    if (head == NULL)
        return;
    postOrder(head->left);
    postOrder(head->right);
    cout << head->data << " ";
}

void postOrderIterative(Node *head) // time complexity O(N);
{
    if (head == NULL)
        return;
    stack<Node *> s1, s2;
    Node *temp;
    s1.push(head);
    while (!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    while (!s2.empty())
    {
        Node *curr = s2.top();
        cout << curr->data << " ";
        s2.pop();
    }
}

int main()
{
    int t;
    cin >> t;
    long a, n;
    Node *head = NULL;
    while (t--)
    {
        cin >> n;
        cin >> a;
        Node *head = makeNode(a);
        long ns = n - 1;
        while (ns--)
        {
            cin >> a;
            insert(head, a);
        }
        levelOrder(head);
        cout << endl;
        cout << "Inorder traversal recurssive ";
        inOrder(head);
        cout << endl;
        cout << "Inorder traversal iterative ";
        inOrderIterative(head);
        cout << endl;
        cout << "preOrder traversal recurssive ";
        preOrder(head);
        cout << endl;
        cout << "preOrder traversal iterative ";
        preOrderIterative(head);
        cout << endl;
        cout << "postOrder traversal recursive ";
        postOrder(head);
        cout << endl;
        cout << "postOrder traversal iterative ";
        postOrderIterative(head);
    }
}