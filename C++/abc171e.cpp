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
	int n;
	cin>>n;
	vector<lli> arr(n);
	vector<lli> xors;
	for(int i=0; i<n; ++i)
		cin>>arr[i];
	for(int i=0; i<n; i+=2){
		xors.push_back(arr[i] ^ arr[i+1]);
	}
	lli total_xor = 0;
	for(auto&x : xors)
		total_xor ^= x;
	for(int i=0; i<n; ++i){
		cout<<(total_xor ^ arr[i])<<" ";
	}
	cout<<endl;
    return 0;
}
