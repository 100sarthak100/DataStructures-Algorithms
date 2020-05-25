#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    if(k > 0 && k <= r - l + 1)
    {
        int pos = randomPartition(arr, l ,r);
        if(pos-1 == k-1)
            return arr[pos];
        if(pos-1 > k-1)
            return kthSmallest(arr, l, pos-1, k);

        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26}; 
    int n = sizeof(arr)/sizeof(arr[0]), k = 3; 
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k); 
    return 0; 
}


// #include <bits/stdc++.h>
// using namespace std;
// const int MSZ = 100001;

// int main() {
//         // given upper bound of N
//     short T;
// 	int N, K, i, j;
// 	cin >> T;
// 	while(T--)
// 	{
// 	    int arr[MSZ] = {0};
// 	    cin >> N;
// 	    while(N--)
// 	    {
// 	        cin >> i;
// 	        arr[i]++;
// 	        //cout<<i<<" "<<arr[i]<<endl;
// 	    }
// 	    cin >> K;
// 	    i = 0;
// 	    j = 0;
// 	    while(j < K)
// 	    {
// 	        j = j + arr[i];
// 	        i++;
// 	        cout<<j<<" "<<i<<endl;
// 	    }
	    
// 	    cout << i-1 << '\n';
// 	}
// }