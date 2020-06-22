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
	int q;
	int x;
	vector<lli> v;
	lli s = 0;
	map<lli, int> freq;
	for(int i=0; i<n; ++i){
		cin>>x;
		v.push_back(x);
		freq[x]++;
		s += x;
	}
	cin>>q;
	lli a, b;
	for(int i=0; i<q; ++i){
		cin>>a>>b;
		s -= a * freq[a];
		s += b * freq[a];
		freq[b] += freq[a];
		freq[a] = 0;
		cout<<s<<endl;
	}
	
    return 0;
}
