// Given a linked list of N nodes. The task is to reverse this list.

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5->6
// Output: 6 5 4 3 2 1
// Explanation: After reversing the list, 
// elements are 6->5->4->3->2->1.

// Example 2:

// Input:
// LinkedList: 2->7->8->9->10
// Output: 10 9 8 7 2
// Explanation: After reversing the list,
// elements are 10->9->8->7->2.

// Time - O(N)
// Space - O(1)

// Iterative method
struct Node *reverseList(struct Node *head)
{
    Node *prev = NULL, *next, *curr = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

// recurssive method
Node* ret;
void recursive(Node* p)
{
    if(p->next == NULL)
   {
       ret = p;
       return;
   }
   recursive(p->next);
   Node* q = p->next;
   q->next = p;
   p->next = NULL;
}


struct Node* reverseList(struct Node *head)
{
   Node* p = head;
   recursive(p);
   return ret;
}
