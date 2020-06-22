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
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
	    v.clear();
	    int n;
	    cin>>n;
	    for(int i=0; i<n; ++i)
		    cin>>arr[i];
	    int prev_max, prev_min;
	    prev_max = arr[0];
	    prev_min = arr[0];
	    int i = 1;
	    bool flag = 0;
	    if(arr[1] > arr[0])
		    flag = 1;
	    while(i < n){
		    if(flag){
			    while(arr[i] > arr[i-1] && i < n){
				    prev_max = arr[i];
				    i += 1;
			    }
			    if(v.size() == 0 || v[v.size()-1] != prev_min)
				    v.push_back(prev_min);
			    v.push_back(prev_max); 
			    prev_min = arr[i];
			    flag = 0;
		    }
		    else{
			    while(arr[i] < arr[i-1] && i < n){
				    prev_min = arr[i];
				    i += 1;
			    }
			    if(v.size() == 0 ||  v[v.size()-1] != prev_max)
				    v.push_back(prev_max);
			    v.push_back(prev_min);
			    prev_max = arr[i];
			    flag = 1;
		    }
	    }
	    if(v[v.size()-1] != arr[n-1])
		    v.push_back(arr[n-1]);
	    cout<<v.size()<<endl;
	    for(auto& x: v)
		    cout<<x<<" ";
	    cout<<endl;

    }
    return 0;
}
