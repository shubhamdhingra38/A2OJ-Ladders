#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl;
#endif
#define MAX 1000000005
using namespace std;
typedef long long int lli;
vector<int> v;
void go(lli x){
	if(x > MAX)
		return;
	v.push_back(x);
	go(10*x + 4);
	go(10*x + 7);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	go(0);
	sort(v.begin(), v.end());
	cout<<lower_bound(v.begin(), v.end(), n) - v.begin()<<endl;
    return 0;
}
