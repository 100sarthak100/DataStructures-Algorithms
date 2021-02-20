// Given an unsorted array of size N of positive integers. One 
// number 'A' from set {1, 2, …N} is missing and one number 'B' 
// occurs twice in array. Find these two numbers.

// Input:
// 2
// 2
// 2 2
// 3 
// 1 3 3

// Output:
// 2 1
// 3 2

// Explanation:
// Testcase 1: Repeating number is 2 and smallest positive missing number is 1.
// Testcase 2: Repeating number is 3 and smallest positive missing number is 2.

// Time Complexity: O(n)
// space - O(1)

// only if arr is not read only 
// METHOD 1

#include<iostream>
using namespace std;

void repeatMiss(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        if(arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else cout<<abs(arr[i])<<" ";
    }
    for(int i = 0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            cout<<(i+1);
            break;
        }
    }
    cout<<endl;
    return;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    repeatMiss(arr, n);
	}
	return 0;
}

// alternate solution, without using space
// Time - O(N)
// Space - O(1)
//METHOD 2

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long n = A.size();
    long S1 = 0, S2 = 0;
    for(int i:A)
    {
        S1 += i;
        S2 += ((long)i)*i;
    }
    
    long E1 = n*(n+1)/2;
    long E2 = n*(n+1)*(2*n+1)/6;
    
    long D1 = S1-E1;
    long D2 = S2-E2;
    
    long DIF = D1;
    long SUM = D2/D1;
    
    long repeat = (SUM+DIF)/2;
    long miss = (SUM-DIF)/2;
    
    return {(int)repeat,(int)miss};
}

// Time - O(N)
// Space - O(1)
// using swap sort method
// only if array is not read only.
//METHOD 3

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int i = 0;
        int *ret = new int[2];
        
        while(i < n)
        {
            if(arr[i] != arr[arr[i]-1])
                swap(arr[i], arr[arr[i]-1]);
            else
                i++;
        }
        
        for(int i = 0; i<n; i++)
        {
            if(arr[i] != (i+1))
            {
                ret[1] = i+1;
                ret[0] = arr[i];
                break;
            }
        }
        
        return ret;
    }
};