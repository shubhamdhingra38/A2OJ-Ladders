//note to self
//---------------------------------------
//you're an idiot, but that's ok
//you'll probably fail a lot, and that's ok
//and don't take this stuff too seriously
//---------------------------------------
#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 100005
int arr[MAX];
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
	    int n, x;
	    cin>>n>>x;
	    for(int i=0; i<n; ++i)
		    cin>>arr[i];
	    int low, high;
	    low = INT_MAX; high = INT_MIN;
	    int s = 0;
	    for(int i=0; i<n; ++i) s+= arr[i];
	    if(s%x != 0){
		    cout<<n<<endl;
		    continue;
	    }
	    for(int i=0; i<n; ++i){
		    if(arr[i]%x != 0){
			    low = min(low, i);
			    high = max(high, i);
		    }
	    }
	    DEBUG(low);
	    DEBUG(high);
	    bool result = true;
	    if(low == INT_MAX) //all numbers in array are divisble by x
		    result = false;
	    if(!result)
		    cout<<-1<<endl;
	    else
		    cout<<max(n-low-1, high)<<endl;
    }
    return 0;
}
