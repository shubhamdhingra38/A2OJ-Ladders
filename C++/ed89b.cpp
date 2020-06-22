#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int a, b;
    int mx, mn;
    int n, x, m;
    while(t--){
		cin>>n>>x>>m;
		mx = mn = x;
		for(int i=0; i<m; ++i){
			cin>>a>>b;
			
			if((a>=mn && a<=mx) || (b>=mn && b<=mx) || (mx>=a && mn<=b)){
				mx = max(mx, b);
				mn = min(mn, a);
			}
		}
		cout<<mx-mn+1<<endl;
		
	}
    return 0;
}
