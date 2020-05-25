// 25525511135, size = 11

#include <bits/stdc++.h>
using namespace std;

void getAllValidIPAddress(vector<string> &result, string s,
                          int index, int count, string ipAddress)
{
    if (s.size() == index && count == 4)
    {
        ipAddress.pop_back();
        result.push_back(ipAddress);
        return;
    }
    
    if(s.size() < index + 1)
        return;
    ipAddress = ipAddress + s.substr(index, 1) + '.';
    //cout<<ipAddress<<" "<<index<<endl;
    getAllValidIPAddress(result, s, index + 1, count + 1, ipAddress);
    ipAddress.erase(ipAddress.end()-2, ipAddress.end());

    if(s.size() < index + 2 || s[index] == '0')
        return;
    ipAddress = ipAddress + s.substr(index, 2) + '.';
    getAllValidIPAddress(result, s, index + 2, count + 1, ipAddress);
    ipAddress.erase(ipAddress.end()-3, ipAddress.end());

    if(s.size() < index + 3 ||
     stoi(s.substr(index, 3)) > 255)
        return;
    ipAddress += s.substr(index, 3) + '.';
    getAllValidIPAddress(result, s, index + 3, count + 1, ipAddress);
    ipAddress.erase(ipAddress.end()-4, ipAddress.end());

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<string> result;
        getAllValidIPAddress(result, s, 0, 0, "");
        for(auto i : result)
            cout<<i<<endl;
    }
}