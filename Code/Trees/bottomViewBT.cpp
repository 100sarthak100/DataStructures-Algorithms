// Given a binary tree, print the bottom view from left to right.
// Input:
// 2
// 1 3 2
// 10 20 30 40 60
// Output:
// 3 1 2
// 40 20 60 30

//                       20
//                     /    \
//                   8       22
//                 /   \     /   \
//               5      3 4     25
//                      /    \      
//                  10       14

// For the above tree the output should be 5 10 4 14 25.

void bottomView(Node *root)
{
   if(root == NULL)
        return;
    map<int, int> data;
    queue<pair<Node*, int>> q;
    int hd = 0;
    q.push(make_pair(root, hd));
    while(!q.empty())
    {
        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        data[hd] = temp->data;
        if(temp->left)
            q.push(make_pair(temp->left, hd-1));
        if(temp->right)
            q.push(make_pair(temp->right, hd+1));
    }
    
    for(auto i : data)
        cout<<i.second<<" ";
}