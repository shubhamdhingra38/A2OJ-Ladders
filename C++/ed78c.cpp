#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
vector<int> v;
map<int, int> diff_right;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n;
		v.clear();
		diff_right.clear();
		for(int i=0; i<2*n; ++i){
			cin>>x;
			v.push_back(x);
		}
		int diff_init = count(v.begin(), v.end(), 1) - count(v.begin(), v.end(), 2);
		DEBUG(diff_init);
		int d = 0;
		diff_right[0] = 0;
		for(int i=n; i<2*n; ++i){
			if(v[i] == 1)
				d++;
			else
				d--;
			if(!diff_right.count(d))
				diff_right[d] = i - n + 1; 
		}
		
		int result = 2 * n;
		d = 0;
		for(int i=n-1; i>=0; --i){
			if(v[i] == 1)
				d++;
			else
				d--;
			if(diff_right.count(diff_init - d))
				result = min(result, n - i + diff_right[diff_init - d]);
		}
		if(diff_right.count(diff_init))
			result = min(result, diff_right[diff_init]);
		cout<<result<<endl;
		
	}
    return 0;
}
