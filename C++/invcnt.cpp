#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 200005
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int arr[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin>>t;
    while(t--){
		cin>>n;
		for(int i=0; i<n; ++i) cin>>arr[i];
		long long int cnt = 0;
		ordered_set s;
		for(int i=n-1; i>=0; --i){
			cnt += s.order_of_key(arr[i]);
			s.insert(arr[i]);
		}
		cout<<cnt<<endl;
	}
    return 0;
}
