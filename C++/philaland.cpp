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
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli ans = 0;
        if(n == 1){
			cout<<1<<endl;
		}
		else{
			while(n){
				ans += 1;
				n = n>>1;
			}
			cout<<ans<<endl;
		}
    }
    return 0;
}
