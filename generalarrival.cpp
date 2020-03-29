#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define whats(x) cout<<#x<<" is "<<x<<endl;
#else
#define whats(x)
#endif
#define REP(n) for(int i=0; i<n; ++i)
#define append push_back
#define ulli unsigned long long int
#define li long int
#define lli long long int
#define endl "\n"


using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin>>n;
    int arr[n];
    REP(n)
        cin>>arr[i];
    int mx, mn;
    int mxi, mni;
    mx = INT32_MIN;
    mn = INT32_MAX;
    REP(n){
        if(arr[i] > mx){
            mx = arr[i];
            mxi = i;
        }
        if(arr[i] <= mn){
            mn = arr[i];
            mni = i;
        }
    }
    if(mxi > mni){
        cout<<(n-mni-1)+(mxi)-1<<endl;
    }
    else{
        cout<<(n-mni-1)+(mxi)<<endl;
    }
    return 0;
}