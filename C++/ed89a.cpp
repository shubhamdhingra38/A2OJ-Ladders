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
	int res;
    int a, b;
    int lg, sm;
    cin>>t;
    while(t--){
		cin>>a>>b;
		int x=min(a,b);
		cout<<min(x, (a+b)/3)<<endl;
	}
    return 0;
}
