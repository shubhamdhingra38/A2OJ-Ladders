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
	int x, y;
	cin>>x>>y;
	//2*n1 + 4*n2 = y
	//n1 + n2 = x
	bool flag = false;
	for(int i=0; i<=x; ++i){
		int res = y - 2 * i;
		if(res%4 == 0 && res/4 == x - i){
			flag = true;
			break;
		}
	}
	cout<<(flag?"Yes":"No")<<endl;
    return 0;
}
