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
    unordered_map<int, int> isTested;
    REP(n){
        cin>>arr[i];
        isTested[arr[i]] = 1;
    }
    for(int i=1; i<= 3001; ++i){
        if(isTested[i] == 0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}