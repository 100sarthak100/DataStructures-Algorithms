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