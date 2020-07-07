// Ceil Value Node: Node with smallest data larger than or equal 
// to key value.

Node* ceil(Node* root, int data)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == data)
        return root;
    
    if(root->data < data)
        return ceil(root->right, data);
    
    int ceilval = ceil(root->left, data);
    if(ceilVal >= data) ? ceilVal : root->data;
}

// Given a Binary Search Tree and a number x, find floor 
// of x in the given BST.
// floor Value Node: Node with smallest data smaller than or equal 
// to key value.

// Input : x = 14 and root of below tree
//             10
//            /  \
//           5    15
//               /  \
//             12    30
// Output : 12

// Input : x = 15 and root of below tree
//             10
//            /  \
//           5    15
//               /  \
//             12    30
// Output : 15 

Node* floor(Node* root, int x)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == x)
        return root;
    
    if(root->data > data)
        return floor(root->left, x);
    
    int floorVal = floor(root->right, x);
    return (floorVal <= x) ? floorVal : root->data;
}