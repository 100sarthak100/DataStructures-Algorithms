// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8

// Input:
// 2
// 1 3 2
// 10 20 30 40 60
// Output:
// 1 2
// 10 30 60

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

void rightView(Node *root)
{
   if(root == NULL) return;
   
   queue<Node*> q;
   queue<Node*> qt;
   q.push(root);
   
   Node* temp;
   
   int level = 1, prevLevel = 0;
   
   cout<<root->data<<" ";
   
   while(!q.empty())
   {
       temp = q.front();
       q.pop();
       
       if(temp->right)
        {
            qt.push(temp->right);
            if(prevLevel < level)
            {
                cout<<temp->right->data<<" ";
                prevLevel = level;
            }
        }
        if(temp->left)
        {
            qt.push(temp->left);
            if(prevLevel < level)
            {
                cout<<temp->left->data<<" ";
                prevLevel = level;
            }
        }
        
        if(q.empty())
        {
            if(q.empty() && qt.empty())
                return;
            level++;
            swap(qt, q);
        }
   }
   return;
}