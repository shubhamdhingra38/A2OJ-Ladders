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
	lli n, m;
	cin>>n>>m;
	lli min, max;
	lli left = n - m;
	max = (left)*(left + 1)/2;
	lli each = n / m + (n % m == 0 ? 0 : 1);
	if(n % m == 0)
		min = m * (each * (each-1))/2;
	else {
		lli mod = n%m;
		min = mod * (each * (each-1))/2 + (m-mod) * ((each-1) * (each-2))/2;
	}
	cout<<min<<" "<<max<<endl;
    return 0;
}
