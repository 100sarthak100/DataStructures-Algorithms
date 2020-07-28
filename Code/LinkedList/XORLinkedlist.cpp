// Following are the nodes of Linked List:
// 40 30 20 10

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* npx; // XOR of next and previous node
};

Node* XOR(Node* a, Node* b)
{
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

Node* makeNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->npx = NULL;
    return newNode;
}

void insert(Node** head_ref, int data)
{
    Node* temp = makeNode(data);
    temp->npx = *head_ref;

    if(*head_ref != NULL)
    {
        (*head_ref)->npx = XOR(temp, (*head_ref)->npx);
    }
    *head_ref = temp;
}

void printList(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while(curr != NULL)
    {
        cout<<curr->data<<" ";
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
}

int main()
{
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    printList(head);
}