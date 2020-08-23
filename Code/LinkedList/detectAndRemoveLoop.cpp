You are given a linked list of N nodes. The task is to remove 
the loop 
from the linked list, if present.

void removeLoopLL(Node* slow, Node* head)
{
    Node* ptr1 = slow;
    Node* ptr2 = slow;
    int k = 1;
    while(ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }
    
    ptr1 = head;
    ptr2 = head;
    for(int i=0; i<k; i++)
        ptr2 = ptr2->next;
        
    while(ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    while(ptr2->next != ptr1)
        ptr2 = ptr2->next;
    
    ptr2->next = NULL;
}

void removeLoop(Node* head)
{
    if(head == NULL)
        return;
    Node* slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            removeLoopLL(slow, head);
            break;
        }
    }
    return;
}