// Given two numbers represented by two linked lists of size 
// N and M. The task is to return a sum list. The sum list is a 
// linked list representation 
// of the addition of two input numbers.

// Input:
// 2
// 2
// 4 5
// 3
// 3 4 5
// 2
// 6 3
// 1
// 7
// Output:
// 3 9 0  
// 7 0

// Explanation:
// Testcase 1: For the given two linked list (4 5) and (3 4 5), 
// after adding the two linked list resultant 
// linked list will be (3 9 0).
// Testcase 2: For the given two linked list (6 3) and (7), 
// after adding the two linked list resultant linked list will be 
// (7 0).

// Time Complexity: O(m + n), 
// Space Complexity: O(m + n).

Node* addTwoLists(Node* first, Node* second) {
    int carry = 0, sum;
    Node* head = NULL, *prev = NULL;
    
    while(first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10 ? 1 : 0);
        sum = sum % 10;
        
        Node* temp = new Node(sum);
        temp->next = head;
        head = temp;
            
        if(first) 
            first = first->next;
        if(second)
            second = second->next;
    }
    if(carry != 0)
    {
        Node* temp = new Node(carry);
        temp->next = head;
        head = temp;
    }
    return head;
}