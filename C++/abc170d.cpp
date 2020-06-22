#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAXVAL 1000005
using namespace std;
typedef long long int lli;

lli mp[MAXVAL];
bool does_not_divide(lli ele){
	for(lli i=2; i*i<=ele; ++i){
		if(ele%i == 0){
			if(mp[ele/i] != 0 || mp[i] != 0){
				return false;
			}
		}
	}
	return mp[ele] == 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(mp, 0, sizeof(mp));
	lli n, x;
	cin>>n;
	vector<lli> v;
	for(int i=0; i<n; ++i){
		cin>>x;
		v.push_back(x);
		mp[x]++;
	}
	if(n == 1){
		cout<<1<<endl;
		return 0;
	}
	int cnt = 0;
	if(mp[1LL] == 0){
		for(int i=0; i<n; ++i){
			bool res = does_not_divide(v[i]);
			cnt += res;
		}
	}
	else if(mp[1LL] == 1){
		cnt++;
	}
	cout<<cnt<<endl;
    return 0;
}
