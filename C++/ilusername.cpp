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

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int arr[n];
    REP(n)
        cin>>arr[i];
    int mx_yet, mn_yet;
    mx_yet = mn_yet = arr[0];
    int res = 0;
    REP(n){
        if(arr[i] > mx_yet){
            mx_yet = arr[i];
            res++;
        }
        if(arr[i] < mn_yet){
            mn_yet = arr[i];
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}