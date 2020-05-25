vector<int> parseInts(string str)
{
    // Complete this function
    stringstream ss(str);
    vector<int> ret;
    while (ss.good())
    {
        int a;
        char ch;
        ss >> a;
        ret.push_back(a);
        ss >> ch;
    }
    return ret;
}