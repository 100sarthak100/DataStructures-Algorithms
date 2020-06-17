void inOrder(Node* root)
{
    if(root == NULL) return;
    stack<Node*> st;
    Node* curr = root;
    
    while(curr != NULL && !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        if(!st.empty())
        {
            curr = st.top();
            st.pop();
            cout<<temp->data<<" ";
            curr = curr->right;
        }
    }
}

void preOrder(Node* root)
{
    if(root == NULL) return;
    stack<Node*> st; 
    Node* curr = root;

    while(curr != NULL && !st.empty())
    {
        while(curr !=  NULL)
        {
            cout<<curr->data<<" ";
            if(curr->right)
                st.push(curr->right);
            curr = curr->left;
        }
        if(!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

lrd
void postOrder(Node* root)
{
    if(root == NULL) return;
    stack<Node*> s1, s2;
    s1.push(root);
    Node* temp;
    while(!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
    while(!s2.empty())
    {
        temp = s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
}









