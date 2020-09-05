#include <bits/stdc++.h>
using namespace std;

void leftRotatebyOne(long long arr[], long long n)
{
    long long temp = arr[0], i;
    for (i = 0; i < n - 1; ++i)
        arr[i] = arr[i + 1];
    arr[i] = temp;
}

void leftRotate(long long arr[], long long d, long long n)
{
    for (long long i = 0; i < d; ++i)
        leftRotatebyOne(arr, n);
}

void printArray(long long arr[], long long n)
{
    for (long long i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    long long n, d, a;

    while (t--)
    {
        cin >> n >> d;
        long long arr[n];
        for (long long i = 0; i < n; ++i)
        {
            //left rotate
            cin >> arr[(i + n - d) % n];
            // right rotate
            // cin>> arr[(i+d)%n];
        }
        printArray(arr, n);
    }
}

// left rotation
vector<int> rotLeft(vector<int> a, int d)
{
    int n = a.size();
    vector<int> ret(n);
    for (int i = 0; i < n; ++i)
        ret[(i + n - d) % n] = a[i];
    return ret;
}

// int main()
// {
//     int t;
//     cin >> t;
//     long long n, d, a;

//     while (t--)
//     {
//         cin >> n >> d;
//         long long arr[n];
//         for (long long i = 0; i < n; ++i)
//         {
//             cin >> a;
//             arr[i] = a;
//         }
//         leftRotate(arr, d, n);
//         printArray(arr, n);
//     }
// }

// right rotate
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		int arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[(i + k)%n];
		for(int i=0; i<n; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}