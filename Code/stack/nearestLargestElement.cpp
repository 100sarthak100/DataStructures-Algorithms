// Given an array arr[ ] of size N having distinct elements, the task is 
// to find the next greater element for each element of the array in order 
// of their appearance in the array.
// Next greater element of an element in the array is the nearest element 
// on the right which is greater than the current element.
// If there does not exist next greater of current element, then next 
// greater element for current element is -1. For example, next greater of 
// the last element is always -1.

// Example 1:

// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1
// Explanation:
// In the array, the next larger element 
// to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
// since it doesn't exist, it is -1.

// Example 2:

// Input: 
// N = 5, arr[] [6 8 0 1 3]
// Output:
// 8 -1 1 3 -1
// Explanation:
// In the array, the next larger element to 
// 6 is 8, for 8 there is no larger elements 
// hence it is -1, for 0 it is 1 , for 1 it 
// is 3 and then for 3 there is no larger 
// element on right and hence -1.

// Time - O(N)
// Space - O(N) -> stack

// Also called Next Greater to Right
// Next greater to left is same , start from left side.

void swap(long long &a, long long &b)
{
    long long temp = a;
    a = b;
    b = temp;
}


void reverseVec(vector<long long> &v)
{
    int i = 0;
    int j = v.size()-1;
    while(i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }
}

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> vec;
    stack<long long> s;
    
    for(int i=n-1; i>=0; i--)
    {
        if(s.size() == 0)
            vec.push_back(-1);
        else if(s.size() > 0 && s.top() > arr[i])
            vec.push_back(s.top());
        else if(s.size() > 0 && s.top() <= arr[i])
        {
            while(s.size() > 0 && s.top() <= arr[i])
                s.pop();
            
            if(s.size() == 0)
                vec.push_back(-1);
            else
                vec.push_back(s.top());
        }
        
        s.push(arr[i]);
    }
    
    reverseVec(vec);
    // for(auto i : vec)
    //     cout<<i<<" ";
    // cout<<endl;
    
    return vec;
}