#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
inline int num_patients(int m, int d){
	return (m-6) * (m-6) + abs(d-15);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //non leap year
	int n;
	cin>>n;
	int r1, r2;
	cin>>r1>>r2;
	int target;
	cin>>target;
	bool flag = false;
	for(int i=0; i<=n; ++i){
		int rev = 0;
		for(int m=1; m<=12; ++m){
			for(int d=1; d<=num_days[m-1]; ++d){
				int nump = num_patients(m, d);
				//DEBUG(nump);
				int t = min(n, nump); //num occupied room
				if(t > n-i)
					rev += (t-n+i) * r1 + r2 * (n-i);
				else
					rev += r2 * t;
			}
		}
		//DEBUG(i);
		//DEBUG(rev);
		if(rev >= target){
			cout<<i<<endl;
			flag = true;
			break;
		}
	}
	if(!flag)
		cout<<n<<endl;
    return 0;
}
