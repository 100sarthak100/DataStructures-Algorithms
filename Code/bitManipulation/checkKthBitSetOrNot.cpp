// bool checkKthBit(int n, int k){
//     return n&(1<<k);
      
// }   
 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n = 4; //12 -0000 1100
    int i = 3;

    if(n & (1 << i))
        cout<<i<<"rd bit is set in "<<n<<endl;
    else
        cout<<i<<"rd bit is NOT set in "<<n<<endl;
 }