// Write a function to check whether an input string is a valid 
// IPv4 address or IPv6 address or neither.

// time O(n)

class Solution {
public:
    string validIPAddress(string IP) {
        istringstream is(IP);
        string t = "";
        int cnt = 0;
        if(IP.find(':') == string::npos)
        {
            while(getline(is, t, '.'))
            {
                ++cnt;
                if(cnt > 4 || t.empty() || (t.size()>1 && t[0] == '0') || t.size()>3)
                    return "Neither";
                for(char c : t)
                    if(c < '0' || c > '9')
                       return "Neither";
                int val = stoi(t);
                if(val < 0 || val > 255)
                    return "Neither";
            }
            return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        }
        else
        {
            while(getline(is, t, ':'))
            {
                ++cnt;
                if(cnt > 8 || t.empty() || t.size() > 4)
                    return "Neither";
                for(char c : t)
                    if(!(c>='0' && c<='9') && !(c>='a' && c<='f') && !(c>='A' && c<='F'))
                        return "Neither";
            }
            return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
    }
};