#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *newN = new Node();
    newN->data = data;
    newN->next = NULL;
    return newN;
}

Node *insertNode(Node *head, int data)
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
    if (temp == NULL)
        return;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// not sure
void deleteNode(Node *node)
{
    // Node *temp = node->next;
    // *node = *(node->next);
    // delete temp;
    Node *prev;
    if (node == NULL)
        return;
    else
    {
        while (node->next != NULL)
        {
            node->data = node->next->data;
            node = node->next;
        }
        node->next = NULL;
    }
}
// working
void deleteWithoutHeadPointer(Node *head)
{
    if (head == NULL)
        return;
    else
    {
        if (head->next == NULL)
        {
            cout << "cant delete the last node";
            return;
        }
        Node *temp = head->next;
        head->data = head->next->data;
        head->next = head->next->next;
        free(temp);
    }
}

Node *findNode(Node *head, int data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    int t, n, a, d;
    cin >> t;
    while (t--)
    {
        Node *head = NULL;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            head = insertNode(head, a);
        }
        //printNodes(head);
        //cout << endl;
        printNodes(head);
        cin >> d;
        Node *nodeSearch = findNode(head, d);
        if (nodeSearch != NULL)
        {
            // deleteNode(nodeSearch);
            deleteWithoutHeadPointer(nodeSearch);
        }
        printNodes(head);
        cout << endl;
    }
}