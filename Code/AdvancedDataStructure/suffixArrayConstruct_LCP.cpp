// Following is suffix array for banana
// 5 3 1 0 4 2

// time - O(n (logn)^2)

// Suffix Array : 
// 5 3 1 0 4 2 

// LCP Array : 
// 1 3 0 0 2 0
// Illustration:

// txt[]     = "banana",  suffix[]  = {5, 3, 1, 0, 4, 2| 

// Suffix array represents
// {"a", "ana", "anana", "banana", "na", "nana"}

// Inverse Suffix Array would be 
// invSuff[] = {3, 2, 5, 1, 4, 0}

#include <bits/stdc++.h>
using namespace std;

struct suffix
{
    int index;
    int rank[2];
};

int cmp(suffix a, suffix b)
{
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
    (a.rank[0] < b.rank[0] ? 1 : 0);
}

int *buildSuffixArray(char *txt, int n)
{
    suffix suffixes[n];
    for(int i=0; i<n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n) ? (txt[i+1] - 'a') : -1;
    }

    sort(suffixes, suffixes+n, cmp);

    int ind[n];

    for(int k=4; k<2*n; k=k*2)
    {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for(int i=1; i<n; i++)
        {
            if(suffixes[i].rank[0] == prev_rank &&
            suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for(int i = 0; i<n; i++)
        {
            int nextIndex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextIndex < n) ?
            suffixes[ind[nextIndex]].rank[0] : -1;
        }
        sort(suffixes, suffixes+n, cmp);
    }
    int *suffixArr = new int[n];
    for(int i = 0; i<n; i++)
        suffixArr[i] = suffixes[i].index;

    return suffixArr;
}

// Kasai's algo to construct LCP array, if suffix array is given
// can construct the LCP array in O(n)

vector<int> kasai(string txt, vector<int> suffixArr) 
{
    int n = suffixArr.size();
    vector<int> lcp(n, 0);
    vector<int> invSuff(n, 0);

    for(int i=0; i<n; i++)
        invSuff[suffixArr[i]] = i;
    
    int k = 0;

    for(int i=0; i<n; i++)
    {
        if(invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }
        int j = suffixArr[invSuff[i] + 1];

        while(i+k<n && j+k<n && txt[i+k] == txt[j+k])
            k++;

        lcp[invSuff[i]] = k;

        if(k > 0)
            k--;
    }
    return lcp;
}

void printArr(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void printArr(vector<int> arr, int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main()
{
    char txt[] = "banana";
    int n = strlen(txt); 

    int *suffixArr = buildSuffixArray(txt,  n); 
    cout << "Following is suffix array for " << txt << endl; 
    printArr(suffixArr, n); 

    vector<int>lcp = kasai(txt, suffixArr); 
    cout << "\nLCP Array : \n"; 
    printArr(lcp, n); 

    return 0;
}