void removeLoop(Node* head)
{
    if(head == NULL || head->next == NULL)
        return;
    Node* slow = head;
    Node* fast = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    
    if(slow == fast)
    {
        slow = head;
        if(fast == head)
        {
            while(fast->next != head)
                fast = fast->next;
        }
        else
        {
            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        fast->next = NULL;
    }
    return;
}