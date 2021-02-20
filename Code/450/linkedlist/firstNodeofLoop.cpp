// Write a function findFirstLoopNode() that checks whether a given 
// Linked List contains a loop. If the loop is present then it returns 
// point to the first node of the loop. Else it returns NULL.

// Output -> Loop starting node is 15

// Time - O(n)
// Space - O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(Node *head)
{
    if (head == NULL)
        return;

    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

Node* firstNode(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }

    if(fast != slow)
        return NULL;
    else
    {
        slow = head;
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->next;
    }
}

int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    Node* res = firstNode(head);    
    if(res == NULL)
        cout<<"Loop doesn't exists."<<endl;
    else
        cout<<"Loop starting node is "<<res->data<<endl;
}