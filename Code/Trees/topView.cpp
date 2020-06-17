// Input:
// 2
// 2
// 1 2 L 1 3 R
// 6
// 10 20 L 10 30 R 20 40 L 20 60 R 30 90 L 30 100 R

// Output:
// 2 1 3
// 40 20 10 30 100

// Explanation:
// Testcase 1:

//            1

//         /     \

//       2        3

// For the above test case the top view is: 2 1 3
// Test case 2:

//             10

//          /        \

//      20          30

//    /      \       /     \

// 40      60 90     100

// TopView is: 40 20 10 30 100


#include <bits/stdc++.h>
using namespace std;

struct Node{ 
    Node * left; 
    Node* right; 
    int data; 
}; 
  
Node* newNode(int key){ 
    Node* node=new Node(); 
    node->left = node->right = NULL; 
    node->data=key; 
    return node; 
} 

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
        cout<<temp[0]<<" ";
        //cout<<endl;
    }
}

int main()
{
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->left->right->right = newNode(5); 
    root->left->right->right->right = newNode(6); 
    cout<<"Following are nodes in top view of Binary Tree\n";  
    verticalOrder(root); 
    return 0; 
}
