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
	int x;
	for(int i=0; i<5; ++i){
		cin>>x;
		if(x == 0){
			cout<<i+1<<endl;
			break;
		}
	}
    return 0;
}
