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
		int n, m;
		cin>>n>>m;
		vector<int> v;
		int x;
		vector<bool> present(m+1);
		for(int i=0; i<n; ++i){
			cin>>x;
			v.push_back(x);
			if(x < m)
				present[x] = true;
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		int count_m = count(v.begin(), v.end(), m);
		bool flag = false;
		for(int i=1; i<m; ++i){
			if(!present[i]){
				flag = true;
				break;
			}
		}
		if(flag)
			cout<<-1<<endl;
		else
			cout<<n - count_m<<endl;
	}
    return 0;
}
