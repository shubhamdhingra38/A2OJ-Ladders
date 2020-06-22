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
	int n, m, r;
	cin>>n>>m>>r;
	vector<int> buy;
	vector<int> sell;
	int x;
	int mn = INT_MAX;
	for(int i=0; i<n; ++i){
		cin>>x;
		mn = min(x, mn);
		buy.push_back(x);
	}
	int mx = INT_MIN;
	for(int i=0; i<m; ++i){
		cin>>x;
		mx = max(x, mx);
		sell.push_back(x);
	}
	int n_buy = r / mn;
	int cash = r;
	cash -= n_buy * mn;
	cash += n_buy * mx;
	cout<<max(r, cash)<<endl;
    return 0;
}
