#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;

lli sum(lli x){
	return (x*(x+1))/2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		lli a, b;
		cin>>a>>b;
		lli mx, mn;
		mx = max(a, b);
		mn = min(a, b);
		lli s;
		if(a == b){
			cout<<0<<endl;
		}
		else{
			int cnt = 1;
			while(1){
				s = sum(cnt) + mn;
				if(s >= mx && (s - mx)%2 == 0)
					break;
				cnt++;
			}
			cout<<cnt<<endl;
		}
	}
    return 0;
}
