#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
bool is_possible(string a, string b){
	map<char, int> m;
	for(int i=0; i<a.size(); ++i)
		m[a[i]]++;
	for(int i=0; i<b.size(); ++i)
		m[b[i]]--;
	for(auto& it: m){
		if(m[it.first] != 0)
			return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		bool f = false;
		string p, h;
		cin>>p>>h;
		if(h.size() < p.size()){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0; i<=h.size()-p.size(); ++i){
			//cout<<h.substr(i, p.size())<<endl;
			if(is_possible(h.substr(i, p.size()), p)){
				f = true;
				break;
			}
		}
		if(f)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
    return 0;
}
