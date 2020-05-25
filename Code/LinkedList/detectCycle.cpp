bool has_cycle(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *slow = head;
    SinglyLinkedListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}