// Consider a big party where a log register for guest’s entry 
// and exit times is maintained. Find the time at which there are
//  maximum guests at the party. Note that entries in the register 
//  are not in any order.  if two events have the same time, 
// then arrival is preferred over the exit.

// Input:
// 2
// 5
// 1 2 10 5 5
// 4 5 12 9 12
// 7
// 13 28 29 14 40 17 3 
// 107 95 111 105 70 127 74 

// Output:
// 3 5
// 7 40

// Time Complexity of this method is O(nLogn)

#include<bits/stdc++.h>
using namespace std;

void maxGuests(int ent[], int ext[], int n)
{
    sort(ent, ent+n);
    sort(ext, ext+n);
    
    int guest_in = 1, guest_max = 1, time = ent[0];
    int i = 1, j = 0;
    while(i < n && j < n)
    {
        if(ent[i] <= ext[j])
        {
            guest_in++;
            if(guest_in > guest_max)
            {
                guest_max = guest_in;
                time = ent[i];
            }
            i++;
        }
        else
        {
            guest_in--;
            j++;
        }
    }
    cout<<guest_max<<" "<<time<<endl;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int entryArr[n], exitArr[n];
	    for(int i=0; i<n; i++)
	        cin>>entryArr[i];
	    for(int i=0; i<n; i++)
	        cin>>exitArr[i];
	   maxGuests(entryArr, exitArr, n);
	}
	return 0;
}