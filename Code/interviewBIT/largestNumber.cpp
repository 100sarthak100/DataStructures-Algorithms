// Given a list of non negative integers, arrange them such that 
// they form the largest number.

// For example:

// Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a 
// string instead of an integer.

bool cmpr(string s1,string s2)
{
    if(s1.append(s2).compare(s2.append(s1)) > 0)
        return true;
    else
        return false;
}

string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    string ret = "";
    if(n == 0)
        return "";
    vector<string> ans(n);
    for(int i =0;i<n;++i)
        ans[i] = to_string(A[i]);
    sort(ans.begin(),ans.end(),cmpr);
    if(ans[0] == "0")
        return "0";
    for(int i =0;i<n;++i)
        ret.append(ans[i]);
    return ret;
}