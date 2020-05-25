// input s="1001011"
//output =ABACA

//huffman decode
void decode_huff(node *root, string s)
{
    node *temp = root;
    string ret = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            temp = temp->left;
        else
            temp = temp->right;
        if (temp->left == NULL && temp->right == NULL)
        {
            ret += temp->data;
            temp = root;
        }
    }
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i];
}