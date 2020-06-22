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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n, q;
	int a, b;
	int where[MAX];
	vector<multiset<int> > v(MAX);
	cin>>n>>q;
	set<int> groups;
	cout<<"HERE"<<endl;
	for(int i=0; i<n; ++i){
		cin>>a>>b;
		groups.insert(b);
		where[a] = b;
		v[b].insert(a);
	}
	int res;
	multiset<int> ranks;
	for(auto&it : groups){
		ranks.insert(*(v[it].begin()));
	}
	cout<<"HERE"<<endl;
	for(int i=0; i<q; ++i){
		cin>>a>>b;
		DEBUG(a);
		DEBUG(b);
		int rb1 = v[where[a]].size() >= 1 ? *(--v[where[a]].end()) : -1;
		int rb2 = v[b].size() >= 1 ? *(--v[b].end()) : -1;
		auto itr = v[where[a]].lower_bound(a);
		if(itr != v[where[a]].end())
			v[where[a]].erase(itr);
		int r1 = *(--v[where[a]].end());
		v[b].insert(a);
		int r2 = *(--v[b].end());
		if(rb1 != r1){
			if(ranks.find(rb1) != ranks.end())
				ranks.erase(rb1);
			ranks.insert(r1);
		}
		if(rb2 != r2){
			if(ranks.find(rb2) != ranks.end())
				ranks.erase(rb2);
			ranks.insert(r2);
		}
		res = *(ranks.begin());
		cout<<res<<endl;
	}
    return 0;
}
