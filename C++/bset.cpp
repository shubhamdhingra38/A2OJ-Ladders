#include<bits/stdc++.h>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
int main(){
	FAST;
	int n;
	unsigned int x;
	cin>>n;
	vector<bitset<20> > v;
	for(int i=0; i<n; ++i){
		cin>>x;
		bitset<20> b(x);
		v.push_back(b);
    }
    for(int i=0; i<20; ++i){
		int cnt = 0;
		for(int j=0; j<n; ++j)
			cnt += (v[j][i]);
		for(int j=n-1; j>=0; --j){
			if(cnt > 0){
				cnt--;
				v[j].set(i);
			}
			else{
				v[j].reset(i);
			}
		}
	}
	lli res = 0;
	for(int i=0; i<n; ++i)
		res += ((lli)v[i].to_ullong())*v[i].to_ullong();
	cout<<res<<endl;
    return 0;
}
