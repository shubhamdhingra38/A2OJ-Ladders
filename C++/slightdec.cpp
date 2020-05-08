#include<bits/stdc++.h>
#define REP(n) for(int i=0; i<n; ++i)
#define append push_back
#define ulli unsigned long long int
#define li long int
#define lli long long int
#define endl "\n"
#ifndef ONLINE_JUDGE
#define whats(x) cout<<#x<<" is "<<x<<endl;
#else
#define whats(x)
#endif


//1 2 3 4 5
//3
//5 1 2 3 4
//5 4 1 2 3
//5 4 3 1 2
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin>>n>>k;
    int arr[n];
    REP(k){
        arr[i] = n-i;
    }
    for(int i=k; i<n; ++i)
        arr[i] = i-k+1;
    REP(n)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}