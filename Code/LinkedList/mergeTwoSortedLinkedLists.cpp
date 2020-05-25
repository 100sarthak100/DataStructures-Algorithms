Node* sortedMerge(Node* head1,   Node* head2)
{
    Node* head, *curr;
    if(head1 == NULL) return head2;
    else if(head2 == NULL) return head1;
    
    if(head1->data <= head2->data)
    {
        curr = head1;
        head1 = head1->next;
    }
    else
    {
        curr = head2;
        head2 = head2->next;
    }
    head = curr;
    
    while(head1 && head2)
    {
        if(head1->data >= head2->data)
        {
            curr->next = head2;
            curr = head2;
            head2 = head2->next;
        }
        else
        {
            curr->next = head1;
            curr = head1;
            head1 = head1->next;
        }
    }
    
    if(head1) curr->next = head1;
    if(head2) curr->next = head2;
    
    return head;
}