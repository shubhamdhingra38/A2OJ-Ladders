#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 100005
using namespace std;
int dp[MAX];
int arr[MAX];
int n;

void go(int x){
	if(x>n)
		return;
	if(dp[x]!=-1)
		return;
	dp[x]=0;
	for(int i=2*x; i<=n; i+=x){
		if(dp[i]==-1)
			go(i);
		if(arr[i]>arr[x])
			dp[x]=max(dp[x],dp[i]+1);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
		cin>>n;
		memset(dp, -1, sizeof(dp[0])*(n+1));
		for(int i=1; i<=n; ++i)
			cin>>arr[i];
		for(int i=1; i<=n; ++i){
			go(i);
		}
		int res=0;
		for(int i=1; i<=n; ++i){
			res=max(dp[i]+1,res);
		}
		cout<<res<<endl;
	}
	
    return 0;
}
