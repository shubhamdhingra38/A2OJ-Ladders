#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
lli nCTwo(lli n){
	return (n*(n-1))/2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t = 1;
	while(t--){
		lli C, x, y, s;
		cin>>C;
		map<lli, lli> freq;
		for(int i=0; i<C; ++i){
			cin>>x>>y>>s;
			lli res = (x*x + y*y)/(s*s);
			freq[res]++;
		}
		int cnt = 0;
		for(auto& it: freq){
			//DEBUG(it.first);
			//DEBUG(it.second);
			if(freq[it.first] > 1)
				cnt += nCTwo(freq[it.first]);
		}
		cout<<cnt<<endl;
	}
    return 0;
}
