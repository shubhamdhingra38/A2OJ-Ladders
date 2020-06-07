#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 500005
using namespace std;
int main(){
    int t;
    int n;
    cin>>t;
    long long int dp[MAX];
    dp[3] = 8;
    long long int num;
    for(int i=2; 2*i+1<MAX; ++i){
        num = 2*i+1;
        dp[num] = i * (2*num + 2*(num-2)) + dp[num-2]; 
    }
    while(t--){
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}