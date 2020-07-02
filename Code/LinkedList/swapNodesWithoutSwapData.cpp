#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* makeNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data)
{
    Node* temp = makeNode(data);
    
    // insert at beginning
    temp->next = *head;
    *head = temp;
}

void printList(Node* head)
{
    if(head == NULL)
        return;
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

void swapNodes(Node** head, int x, int y)
{
    if(x == y)
        return;
    
    // search for x
    Node* prevX = NULL, *currX = *head;
    while(currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    // search for y
    Node* prevY = NULL, *currY = *head;
    while(currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if(currX == NULL || currY == NULL)
        return;
    
    // If x is not head of linked list  
    if(prevX != NULL)
        prevX->next = currY;
    else
        *head = currY;

    // If y is not head of linked list  
    if (prevY != NULL)  
        prevY->next = currX;  
    else  
        *head = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

int main()
{
    Node* head = NULL;
    insert(&head, 7);  
    insert(&head, 6);  
    insert(&head, 5);  
    insert(&head, 4);  
    insert(&head, 3);  
    insert(&head, 2);  
    insert(&head, 1);

    printList(head);  
    cout<<endl;
    swapNodes(&head, 1, 7);  
    printList(head);  
}