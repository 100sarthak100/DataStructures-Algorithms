#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Node *insert(Node *head, int data)
{
    if (head == NULL)
        return head = newNode(data);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode(data);
    return head;
}

void printNodes(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        return;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int n, m, data;
    cin >> n >> m;
    while (n--)
    {
        cin >> data;
        head1 = insert(head1, data);
    }
    while (m--)
    {
        cin >> data;
        head2 = insert(head2, data);
    }
    printNodes(head1);
    cout << endl;
    printNodes(head2);
    cout << endl;
    Node *point = intersectPoint(head1, head2, n, m);
    cout << point->data << " ";
}

// using set (TLE)
ListNode *Solution::getIntersectionNode(ListNode *A, ListNode *B)
{
    int n = length(A);
    int m = length(B);

    set<ListNode *> s;
    for (int i = 0; i < n; i++)
    {
        ListNode *temp = A;
        while (temp->next != NULL)
        {
            s.insert(temp);
            temp = temp->next;
        }
        s.insert(temp);
    }
    for (int i = 0; i < m; i++)
    {
        if (s.find(B) != s.end())
            return B;
        B = B->next;
    }
    return NULL;
}

// best soln
ListNode *Solution::getIntersectionNode(ListNode *A, ListNode *B)
{
    int n = length(A);
    int m = length(B);
    int d = n - m;
    if (m > n)
    {
        ListNode *temp = A;
        A = B;
        B = temp;
        d = m - n;
    }
    for (int i = 0; i < d; ++i)
        A = A->next;

    while (A != NULL && B != NULL)
    {
        if (A == B)
            return A;
        A = A->next;
        B = B->next;
    }

    return NULL;
