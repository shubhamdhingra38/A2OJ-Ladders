#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
int turnOffK(int n, int k){ 
    if (k <= 0) return n; 
    return (n & ~(1 << (k - 1))); 
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; ++i){
		cin>>x;
		v.push_back(x);
	}
	lli res = 0;
	for(int i=0; i<20; ++i){
		int cnt = 0;
		for(int j=0; j<n; ++j){
			if((v[j]>>i)&1)
				cnt++;
		}
		int num = 1<<i;
		DEBUG(num);
		DEBUG(cnt);
		for(int j=n-1; j>=0; --j){
			if(cnt > 0){
				cnt--;
				v[j] |= num;
			}
			else
				v[j] = turnOffK(v[j], i+1);
		}
		//DEBUG(cnt);
		//int curr = (1<<cnt)-1;
		//curr *= curr;
		//res += curr;
	}
	for(int i=0; i<n; ++i)
		res += (lli)v[i]*(lli)v[i];
	cout<<res<<endl;
    return 0;
}
