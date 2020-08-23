// Given a string that contains ternary expressions. The 
// expressions may be nested. You need to convert the given 
// ternary expression 
// to a binary Tree and return the root.

// Input:
// 2
// a?b:c
// a?b?c:d:e
// Output:
// a b c
// a b c d e

// Explanation:
// Testcase1:
// Input :  string expression =   a?b:c
// Output :        a
//               /  \
//              b    c
// Testcase2:

// Input : expression =  a?b?c:d:e
// Output :          a
//                 /  \
//               b    e
//              /  \
//             c    d

// Time Complexity : O(n) [ here n is length of String ]

Node *convertExpression(string str,int i)
{
    if(i == str.size())
        return NULL;
    
    Node* root = new Node(str[i]);
    
    if(i+1 < str.size() && str[i+1] == '?')
        root->left = convertExpression(str, i+2);
    
    if(i+1 < str.size() && str[i+1] == ':')
        root->right = convertExpression(str, i+2);
    
    return root;
}