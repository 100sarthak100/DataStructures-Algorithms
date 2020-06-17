// Given two binary trees, the task is to find if both of them are identical or not. 
// Input:
// 3
// 1 2 3
// 1 2 3
// 1 2 3
// 1 3 2
// 1 2 3 N 3 N 10
// 1 2 3 N 3 N 10
// Output:
// Yes
// No
// Yes
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

bool isIdentical(Node *r1, Node *r2)
{
    if(r1 == NULL && r2 == NULL)
        return true;
    if(r1 == NULL) return false;
    if(r2 == NULL) return false;
    
    if(r1->data != r2->data)
        return false;
    return (isIdentical(r1->left, r2->left) &&
           isIdentical(r1->right, r2->right));
}