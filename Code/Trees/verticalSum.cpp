//       1
//     /   \
//   2      3
//  / \    / \
// 4   5  6   7

// The tree has 5 vertical lines
// Vertical-Line-1 has only one node 4 => vertical sum is 4
// Vertical-Line-2: has only one node 2=> vertical sum is 2
// Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
// Vertical-Line-4: has only one node 3 => vertical sum is 3
// Vertical-Line-5: has only one node 7 => vertical sum is 7

// Input:
// 2
// 1 2 3 4 5 6 7
// 5 2 3 1 7 6 N
// Output:
// 4 2 12 3 7 
// 1 2 18 3 

void verticalSum(Node *root) {
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
    int sum = 0;
    for(auto i : data)
    {
        sum = 0;
        for(auto x : i.second)
            sum += x;
        cout<<sum<<" ";
    }
    return;
}