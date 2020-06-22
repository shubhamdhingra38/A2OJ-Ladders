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
	int t;
	cin>>t;
	while(t--){
		int n, b, m;
		cin>>n>>b>>m;
		vector<int> v;
		int x;
		for(int i=0; i<m; ++i){
			cin>>x;
			v.push_back(x);
		}
		int curr_blk = -1;
		int res = 0;
		for(int i=0; i<m; ++i){
			int blk = v[i]/b;
			if(blk != curr_blk){
				curr_blk = blk;
				res++;
			}
		}
		cout<<res<<endl;
	}
    return 0;
}
