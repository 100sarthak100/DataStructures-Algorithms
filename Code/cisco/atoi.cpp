// ascii to integer
#include <bits/stdc++.h>
using namespace std;

int myatoi(char* str)
{
    int sign = 1;
    int res = 0;
    int i = 0;

    if(str[0] == '-')
    {
        sign = -1;
        i++;
    }

    for(; str[i] != '\0'; i++)
        res = res * 10 + (str[i] - '0');
    
    return sign*res;
}

int main()
{
    char arr[] = "-1234";
    int n = myatoi(arr);
    cout<<n-1<<endl;
}