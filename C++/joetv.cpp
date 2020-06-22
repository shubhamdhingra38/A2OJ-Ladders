#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl;
#endif
using namespace std;
typedef long long int lli;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<long double> dp(n+10);
	dp[1] = (long double)1;
	for(int i=2; i<=n; ++i){
		dp[i] = dp[i-1] + (long double)(1)/i;
	}
	cout<<fixed;
	cout<<setprecision(10)<<dp[n]<<endl;
    return 0;
}
