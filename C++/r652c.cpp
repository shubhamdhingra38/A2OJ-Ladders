#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 
using namespace std;
typedef long long int lli;
bool is_good(lli x){
	if(x%2 == 0)
		return false;
	for(lli i=2; i*i <= x; ++i){
		if(x%i == 0){
			lli d1, d2;
			d1 = x/i;
			d2 = i;
			if(d1&1 || d2&1)
				return false;
		}
	}
	return true;
}

bool is_winning(lli x){
	bool flag = false;
	if(x&1 && x != 1)
			flag = true;
	else if(x == 2)
		flag = true;
	else{
		for(lli i=2; i*i <= x; ++i){
			if(x%i == 0){
				lli d1, d2;
				d1 = x/i;
				d2 = i;
				if(d1&1 && !is_winning(x/d1)){
					flag = true;
					//DEBUG(d1);
					//DEBUG(d2);
					break;
				}
				if(d2&1 && !is_winning(x/d2)){
					flag = true;
					//DEBUG(d1);
					//DEBUG(d2);
					break;
				}
			}
		}
	}
	return flag;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		bool flag = is_winning(n);
		cout<<(flag?"Ashishgup":"FastestFinger")<<endl;
	}
    return 0;
}
