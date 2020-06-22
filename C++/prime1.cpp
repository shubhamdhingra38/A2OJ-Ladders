#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
typedef long long int lli;
using namespace std;

bool is_prime(lli x){
	for(lli i=2; i*i<=x; ++i){
		if(x%i == 0)
			return false;
	}
	return true;
}

void print_primes(lli l, lli r){
	for(lli i=l; i<=r; ++i){
		if(i >= 2 && is_prime(i))
			cout<<i<<endl;
	}
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int l, r;
    cin>>t;
    while(t--){
		cin>>l>>r;
		print_primes(l, r);
	}
    return 0;
}
