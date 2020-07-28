#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* newNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(Node** head, int data)
{
    if(*head == NULL)
        *head = newNode(data);
    else
    {
        Node* temp = newNode(data);
        temp->next = *head;
        *head = temp;
    }
    return;
}

void printLL(Node* head)
{
    if(head == NULL)
        return;
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

Node* findNode(Node* head, int data)
{
    if(head == NULL)
        return NULL;
    while(head->data != data)
        head = head->next;
    return head;
}

void insertAfterNode(Node* head, int data, int prevData)
{
    Node* prev_Node = findNode(head, prevData);

    if(prev_Node == NULL)
        return;
    Node* newN = newNode(data);
    newN->next = prev_Node->next;
    prev_Node->next = newN;
}

void insertAtEnd(Node** head, int data)
{
    if(*head == NULL)
    {
        *head = newNode(data);
        return;
    }

    Node* temp = newNode(data);
    temp->next = NULL;
    Node* last = *head;

    while(last->next != NULL)
        last = last->next;
    last->next = temp;
    return;
}

void deleteNode(Node** head, int data)
{
    if(*head == NULL)
        return;

    Node* temp = *head;
    if(temp->data == data)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    while(temp->next->data != data)
        temp = temp->next;
    Node* tofree(temp->next);
    temp->next = temp->next->next;
    free(tofree);
}

int lengthll(Node** head)
{
    if(*head == NULL)
        return 0;
    Node* temp = *head;
    int count = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void deleteNthNodefromEnd(Node** head, int n)
{
    if(*head == NULL)
        return;

    int length = lengthll(head);
    if(n > length)
        return;

    int diff = length - n;

    Node* temp = *head;
    if(diff == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    
    diff--;
    while(diff--)
        temp = temp->next;
    Node* tofree = temp->next;
    temp->next = temp->next->next;
    free(tofree);
    return;
}

void deleteWithoutHeadPointer(Node* to_del)
{
    Node* temp = to_del->next;
    to_del->data = temp->data;
    to_del->next = temp->next;
    free(temp);
}

int main()
{
    Node* head = NULL;
    insertFront(&head, 1);
    insertFront(&head, 2);
    insertFront(&head, 3);
    insertFront(&head, 4);

    cout<<"insert at front"<<endl;
    printLL(head);
    cout<<endl;

    insertAfterNode(head, 6, 4);
    cout<<"insert after "<<endl;
    printLL(head);
    cout<<endl;

    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 11);
    cout<<"insert at th end"<<endl;
    printLL(head);
    cout<<endl;

    deleteNode(&head, 11);
    cout<<"after delete node"<<endl;
    printLL(head);
    cout<<endl;

    deleteNthNodefromEnd(&head, 5);
    cout<<"after delete nth node from end"<<endl;
    printLL(head);
}