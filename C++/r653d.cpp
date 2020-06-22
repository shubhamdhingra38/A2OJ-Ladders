#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 200005
using namespace std;
typedef long long int lli;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pair<int, int> dp[2][MAX];
	int n, k;
	cin>>n>>k;
	int x;
	vector<int> v;
	for(int i=0; i<n; ++i){
		cin>>x;
		v.push_back(x);
	}
	for(int i=0; i<=k; ++i){
		dp[0][i] = {INT_MAX, INT_MAX};
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=k; ++j){
			if(j > i)
				break;
			int d1, d2;
			if(j%2 == 0){
				if(dp[0][j-1].second == INT_MAX)
					x = 0;
				else 
					x = dp[0][j-1].second;
				d1 = min(max(v[i-1], x), dp[0][j-1].first);
				d2 = min(dp[0][j].first, dp[0][j].second);
				if(d1 < d2){
					dp[1][j] = {max(v[i-1], x), dp[0][j-1].first};
				}
				else{
					dp[1][j] = {dp[0][j].first, dp[0][j].second};
				}
			}
			else{
				if(dp[0][j-1].first == INT_MAX)
					x = 0;
				else 
					x = dp[0][j-1].first;
				d1 = min(max(v[i-1], x), dp[0][j-1].second);
				d2 = min(dp[0][j].first, dp[0][j].second);
				if(d1 > d2){
					dp[1][j] = {max(v[i-1], x), dp[0][j-1].second};
				}
				else{
					dp[1][j] = {dp[0][j].first, dp[0][j].second};
				}
			}
		}
		for(int j=1; j<=k; ++j){
			DEBUG(dp[1][j].first);
			DEBUG(dp[1][j].second);
			dp[0][j] = dp[1][j];
		}
	}
	cout<<min(dp[1][k].first, dp[1][k].second)<<endl;
	
    return 0;
}
