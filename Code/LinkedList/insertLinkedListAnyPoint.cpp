SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *head, int data, int position)
{
    if (head == NULL)
        return NULL;
    if (position == 0)
    {
        SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    SinglyLinkedListNode *temp = head;
    int i = 0;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}