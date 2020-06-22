#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 100005
using namespace std;
int arr[MAX];

bool check(int x, int n, int c){
	int count = 1;
	int last_cow = arr[0];
	for(int i=1; i<n; ++i){
		if(arr[i]-last_cow >= x){
			last_cow = arr[i];
			count++;
		}
	}
	return count >= c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int c, n;
    while(t--){
		cin>>n>>c;
		for(int i=0; i<n; ++i) cin>>arr[i];
		sort(arr, arr+n);
		int result = 0;
		int l, r, mid;
		l = 1;
		r = arr[n-1];
		//DEBUG(r);
		while(l <= r){
			mid = (l+r)/2;
			if(check(mid, n, c)){
				l = mid+1;
				result = max(result, mid);
			}
			else
				r = mid-1;
		}
		cout<<result<<endl;
	}
    return 0;
}
