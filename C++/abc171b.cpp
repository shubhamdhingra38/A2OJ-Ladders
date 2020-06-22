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
	int n, k;
	cin>>n>>k;
	vector<int> v;
	int x;
	for(int i=0; i<n; ++i){
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for(int i=0; i<k; ++i)
		sum += v[i];
	cout<<sum<<endl;
    return 0;
}
