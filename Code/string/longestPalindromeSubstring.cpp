#include <bits/stdc++.h>
using namespace std;

void printSubstr(char *str, int start, int end)
{
    for (int i = start; i <= end; i++)
        cout << str[i];
    cout << endl;
}

int longestPalSubstr(char *str)
{
    int maxLength = 1;
    int start = 0;
    int len = strlen(str);
    int low, high;
    for (int i = 1; i < len; ++i)
    {
        //cout<<low<<" "<<high<<endl;
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }

        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    printSubstr(str, start, start + maxLength - 1);
    cout << endl;
    return maxLength;
}

int main()
{
    char str[] = "forgeeksskeegfor";
    cout << "\nLength is: " << longestPalSubstr(str) << endl;
    return 0;
}