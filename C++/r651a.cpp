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
	int n;
	while(t--){
		cin>>n;
		if(n%2 != 0){
			n--;
		}
		cout<<n/2<<endl;
	}
    return 0;
}
