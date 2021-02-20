// Given a linked list of size N. The task is to reverse every k 
// nodes (where k is an input to the function) in the linked list.

// Example 1:

// Input:
// LinkedList: 1->2->2->4->5->6->7->8
// K = 4
// Output: 4 2 2 1 8 7 6 5 
// Explanation: 
// The first 4 elements 1,2,2,4 are reversed first 
// and then the next 4 elements 5,6,7,8. Hence, the 
// resultant linked list is 4->2->2->1->8->7->6->5.

// Example 2:

// Input:
// LinkedList: 1->2->3->4->5
// K = 3
// Output: 3 2 1 5 4 
// Explanation: 
// The first 3 elements are 1,2,3 are reversed 
// first and then elements 4,5 are reversed.Hence, 
// the resultant linked list is 3->2->1->5->4.

// Time - O(n)
// Space - O(1)

struct node *reverse (struct node *head, int k)
{ 
    if(head == NULL)
        return NULL;
        
    node* prev = NULL, *curr = head, *next = NULL;
    int counter = k;
    while(curr != NULL && counter--)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    if(next != NULL)
        head->next = reverse(next, k);
    
    return prev;
}