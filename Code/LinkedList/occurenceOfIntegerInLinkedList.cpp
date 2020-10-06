// Given a singly linked list and a key, count number of occurrences 
// of given key in linked list. For example, if given linked list is 
// 1->2->1->2->1->3->1 and given key is 1, 
// then output should be 4.

// Example:
// Input:
// 1
// 8
// 1 2 2 4 5 6 7 8
// 2

// Output:
// 2

// Explanation:
// Testcase 1: 2 is occurring twice in the given linked list.

int count(struct node* head, int search_for)
{
    int count = 0;
    while(head != NULL)
    {
        if(head->data == search_for)
            count++;
        head = head->next;
    }
    return count;
}