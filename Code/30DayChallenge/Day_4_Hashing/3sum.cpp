// Time complexity: O(N^2).
// There are only two nested loops traversing the array, 
// so time complexity is O(n^2).
// Space Complexity: O(1).

// with hashing and extra space for hash table
#include<bits/stdc++.h>
using namespace std;

int Threesum(int arr[], int n, int s)
{
    for(int i=0; i<n-2; i++)
    {
        unordered_set<int> st;
        int cur_sum = s - arr[i];
        for(int j=i+1; j<n; j++)
        {
            int k = cur_sum - arr[j];
            if(st.find(k) != st.end())
            {
                return 1;
            }
            else
                st.insert(arr[j]);
        }
    }
    return 0;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, s;
	    cin>>n>>s;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   cout<<Threesum(arr, n, s)<<endl;
	}
	return 0;
}

// without extra space
// two pointer method
#include<bits/stdc++.h>
using namespace std;

int Threesum(int arr[], int n, int s)
{
    sort(arr, arr+n);
    for(int i=0; i<n-2; i++)
    {
        int left = i+1;
        int right = n-1;
        while(left < right)
        {
            int curSum = arr[i] + arr[left] + arr[right];
            if(s == curSum)
            {
                //cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right];
                return 1;
            }
            else if(curSum < s)
                left++;
            else
                right--;
        }
        
    }
    return 0;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, s;
	    cin>>n>>s;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   cout<<Threesum(arr, n, s)<<endl;
	}
	return 0;
}

// 3 sum (sum == 0) triplets print all
// can print any sum == k triplets
// two pointers
// best method

// TIME - O(N^2)
// Space - O(N)
// sort - O(n logn) < O(N*2)
// also works for duplicates
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> vec;
        if(n == 0)
            return ret;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++)
        {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                int low = i+1;
                int high = n-1;
            
                 while(low < high)
                {
                     int sum = nums[i] + nums[low] + nums[high];
                     // sum == k
                     if(sum == 0)
                     {
                         vec = {nums[i], nums[low], nums[high]};
                         ret.push_back(vec);
                         vec.clear();
                         while(low < high && nums[low] == nums[low+1])
                             low++;
                         while(low < high && nums[high] == nums[high-1])
                             high--;
                         low++;
                         high--;
                     }
                     else if(sum < 0)
                         low++;
                     else
                         high--;
                }
            }  
        }
        return ret;
    }
};

/////// Triplet sum in array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j=low; j<high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
        
    }
}

bool checkVal(int arr[], int i, int j, int k, int X)
{
    while(j < k)
    {
        int ans = arr[i] + arr[j] + arr[k];
        if(ans == X)
            return true;
        else if(ans < X)
            j++;
        else if(ans > X)
            k--;
    }
    
    return false;
}

bool find3Numbers(int arr[], int N, int X)
{
    sort(arr, arr+N);
    for(int i=0; i<N-2; i++)
    {
        if(checkVal(arr, i, i+1, N-1, X))
            return true;
    }
    
    return false;
}
