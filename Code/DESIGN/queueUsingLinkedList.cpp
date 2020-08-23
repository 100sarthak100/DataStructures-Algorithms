// Time complexity of both operations enqueue() and 
// dequeue() is O(1) as we only change few pointers in 
// both operations. 
// There is no loop in any of the operations.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Queue
{
    Node *rear, *front;
    Queue()
    {
        rear = front = NULL;
    }

    void enqueue(int x)
    {
        Node* temp = new Node(x);
        if(rear == NULL)
        {
            rear = front = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
        return;
    }

    void dequeue()
    {
        if(front == NULL)
            return;
        
        Node* temp = front;
        front = front->next;

        if(front == NULL)
            rear = NULL;
        
        delete(temp);
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout<<(q.front)->data<<endl;
    cout<<(q.rear)->data<<endl;

}