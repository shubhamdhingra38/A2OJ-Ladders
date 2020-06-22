#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
typedef long long int lli;
using namespace std;

struct node{
	int val = -1;
};
map<int, node> m;

lli go(lli x){
	if(x <= 0)
		return 0;
	if(m[x].val != -1)
		return m[x].val;
	lli res;
	res = max(go(x/2) + go(x/3) + go(x/4), x);
	m[x].val = res;
	return res;
}

int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    while(cin>>n){
		cout<<go(n)<<endl;
	}
    return 0;
}
