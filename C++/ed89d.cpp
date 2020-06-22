#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 500005
typedef long long int lli;
using namespace std;
lli arr[MAX];
lli l1[MAX], l2[MAX];
int n;
void solve(lli ele, int idx){
	for(lli i=2; i*i<=ele; ++i){
		if(ele%i == 0){
			lli d = ele/i;
			lli g = gcd(i+d, ele);
			if(g == 1){
				l1[idx] = d;
				l2[idx] = i;
				return;
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    memset(l1, -1, sizeof(l1));
    memset(l2, -1, sizeof(l2));
    for(int i=0; i<n; ++i) cin>>arr[i];
    for(int i=0; i<n; ++i){
		int x = arr[i];
		solve(x, i);
	}
	for(int i=0; i<n; ++i){
		cout<<l1[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<n; ++i){
		cout<<l2[i]<<" ";
	}
	cout<<endl;
    return 0;
}
