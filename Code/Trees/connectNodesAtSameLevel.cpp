// Given a binary tree, connect the nodes that are at same level.
// Input:
// 2
// 3 1 2
// 10 20 30 40 60
// Output:
// 3 1 2
// 1 3 2
// 10 20 30 40 60
// 40 20 60 10 30

// Explanation:
// Testcase1: The connected tree is
//         3 ------> NULL
//      /      \
//    1 -----> 2 ------ NULL
// Testcase2: The connected tree is
//                            10 ----------> NULL
//                         /        \
//                      20 ------> 30 -------> NULL
//                   /       \
//                40 ----> 60 ----------> NULL

struct Node
{
      int data;
      Node* left;
      Node* right;
      Node* nextRight;
}

void connect(Node *p)
{
   queue<Node*> q;
   q.push(p);
   queue<Node*> qt;
   while(!q.empty())
  {
        Node* temp = q.front();
        q.pop();
        if(temp->left)
            qt.push(temp->left);
        if(temp->right)
            qt.push(temp->right);
        if(!q.empty())
            temp->nextRight = q.front();
        if(q.empty())
        {
            temp->nextRight = NULL;
            swap(qt, q);
        }
  }
  return;
}