// Given a singly linked list consisting of N nodes. The 
// task is to remove 
// duplicates (nodes with duplicate values) from the given 
// list (if exists).
// Note: Try not to use extra space. Expected time complexity 
// is O(N). The nodes are arranged in a sorted way.

// Example 1:

// Input:
// N = 4
// value[] = {2,2,4,5}
// Output: 2 4 5
// Explanation: In the given linked list 
// 2 ->2 -> 4-> 5, only 2 occurs more 
// than 1 time.
// Example 2:

// Input:
// N = 5
// value[] = {2,2,2,2,2}
// Output: 2
// Explanation: In the given linked list 
// 2 ->2 ->2 ->2 ->2, 2 is the only element
// and is repeated 5 times.

// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)

Node *removeDuplicates(Node *root)
{
    if(root == NULL)
        return NULL;
    Node* temp = root->next;
    Node* prev = root;
    while(temp != NULL)
    {
        if(prev->data == temp->data)
        {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return root;
}