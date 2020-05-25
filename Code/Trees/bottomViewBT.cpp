#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int hd;
    Node *left, *right;

    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};

void bottomView(Node *root)
{
    if(root == NULL)
        return;
    
    int hd = 0;
    map<int, int> m;

    queue<Node*> q;

    root->hd = hd;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        hd = temp->hd;

        m[hd] = temp->data;
        cout<<hd<<" "<<temp->data<<endl;

        if(temp->left != NULL)
        {
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }

        if(temp->right != NULL)
        {
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }
    for(auto i = m.begin(); i != m.end(); ++i)
        cout<<i->second<<" "; 
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root); 
    return 0;
}

void Bottom(Node* root, int arr[], int arr2[], int x, int p, int mid)
{
    if(root == NULL)
        return;
    
    if(x < l)
        l = x;

    if(x > r)
        r = x;

    if(arr[mid + x] == INT_MIN)
    {
        arr[mid + x] = root->data;
        arr2[mid + x] = p;
    }
    else if(arr2[mid + x] < p)
    {
        arr[mid + x] = root->data;
        arr2[mid + x] = p;
    }

    Bottom(root->right, arr, arr2, x+1, p+1, mid);
    Bottom(root->left, arr, arr2, x-1, p+1, mid);
}

void bottomView(Node* root)
{
    int arr[2 * N + 1];
    int arr2[2 * N + 1];

    for(int i = 0; i < 2*N+1; i++)
    {
        arr[i] = INT_MIN;
        arr2[i] = INT_MIN;
    }

    int mid = N, x = 0, p = 0;

    Bottom(root, arr, arr2, x, p, mid);

    for(int i = mid + l; i <= mid + r; i++)
        cout<<arr[i]<<" ";
}