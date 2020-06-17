// Input:
// 3
// 2 N 3 4 N
// 1 2 3 4 5 N 6
// 3 1 5 N 2 4 7 N N N N 6 
// Output:
// 2 4 3
// 4 2 1 5 3 6
// 1 3 2 4 5 6 7
// Explanation:
// Testcase1:
//          2
//            \
//             3
//             /
//          4
// As it is evident from the above diagram that during vertical traversal 2, 4 will come first, then 3. So output is 2 1 5 3
// Testcase2:
//              1
//            /     \
//          2       3
//       /     \        \
//     4       5       6
// As it is evident from the above diagram that during vertical traversal 4 will come first, then 2, then 1,5, then 3 and then 6. So the output is 4 2 1 5 3 6.
// Time Complexity of above implementation is O(n Log n)

void verticalOrder(Node *root)
{
    if(root == NULL)
        return;
    map<int, vector<int>> data;
    queue<pair<Node*, int>> q;
    int hd = 0;
    q.push(make_pair(root, hd));
    while(!q.empty())
    {
        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        data[hd].push_back(temp->data);
        if(temp->left)
            q.push(make_pair(temp->left, hd-1));
        if(temp->right)
            q.push(make_pair(temp->right, hd+1));
    }
    
    for(auto i : data)
    {
        vector<int> temp = i.second;
        for(auto x : temp)
            cout<<x<<" ";
    }
}
