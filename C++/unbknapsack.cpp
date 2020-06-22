#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 2005
using namespace std;
int n, k;
int arr[MAX];
bool dp[MAX];
int unbounded_knapsack(){
    for(int i=0; i<=k; ++i)
        dp[i]=false;
    dp[0]=true;
    for(int i=1; i<=k; ++i){
        for(int j=0; j<n; ++j){
            if(i-arr[j]>=0)
                dp[i] = dp[i]|dp[i-arr[j]];
        }
    }
    int v=k+1;
    while(v--){
        if(dp[v]==true)
            return v;
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0; i<n; ++i)
            cin>>arr[i];
        int res = unbounded_knapsack();
        cout<<res<<endl;
    }
    return 0;
}
