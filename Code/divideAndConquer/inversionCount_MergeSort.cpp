// input -
// 5
// 1 4 3 2 5

// output -
// 3

// Time - O(nlogn)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll merge(ll arr[], ll l, ll m, ll r)
{
	ll n1 = m - l + 1;
	ll n2 = r - m;
	ll arr1[n1], arr2[n2];
	for(ll i=0; i<n1; i++)
		arr1[i] = arr[l + i];
	for(ll i=0; i<n2; i++)
		arr2[i] = arr[m + 1 + i];
	
	ll i=0, j=0, k=l;
	ll count = 0;
	while(i < n1 && j < n2)
	{
		if(arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
			count += n1 - i;
		}
		k++;
	}
	while(i < n1)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}
	return count;
}

ll mergeSort(ll arr[], ll l, ll r)
{
	ll count = 0;
	if(l < r)
	{
		ll mid = l + (r - l)/2;
		count += mergeSort(arr, l, mid);
		count += mergeSort(arr, mid+1, r);
		count += merge(arr, l, mid, r);
	}
	return count;
}

int main()
{
	ll n;cin>>n;
	ll arr[n];
	for(ll i=0; i<n; i++)
		cin>>arr[i];
	cout<<mergeSort(arr, 0, n-1)<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}