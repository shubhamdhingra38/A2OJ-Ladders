#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
vector<int> v;
int n, k;

bool check(int ele, bool init){
	int count = 0;
	for(int i=0; i<n; ++i){
		if(!init){
			count++;
			init = !init;
		}
		else{
			if(v[i] <= ele){
				count++;
				init = !init;
			}
		}
	}
	return count >= k;
}

int bin_search(int start, int end){
	int ans = 1e9;
	while(start <= end){
		int mid = (start + end)/2;
		if(check(mid, false) || check(mid, true)){
			ans = min(ans, mid);
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	cin>>n>>k;
	for(int i=0; i<n; ++i){
		cin>>x;
		v.push_back(x);
	}
	int ans = bin_search(1, 1e9);
	cout<<ans<<endl;
    return 0;
}
