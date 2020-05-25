// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]  ->inorder return


class Solution {
public:
    TreeNode* newNode(int data)
    {
        TreeNode* newnode = new TreeNode;
        newnode->val = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        TreeNode* head = newNode(preorder[0]);
        s.push(head);
        TreeNode* temp;
        for(int i = 1;i<preorder.size();i++)
        {
            temp = NULL;
            while(!s.empty() && preorder[i] > s.top()->val)
            {
                temp = s.top();
                s.pop();
            }
            if(temp != NULL)
            {
                temp->right = newNode(preorder[i]);
                s.push(temp->right);
            }
            else
            {
                temp = s.top();
                temp->left = newNode(preorder[i]);
                s.push(temp->left);
            }
        }
        return head;
    }
};