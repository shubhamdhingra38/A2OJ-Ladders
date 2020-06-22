#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 100005
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    bool present[MAX];
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; ++i){
	    cin>>x;
	    v.push_back(x);
    }
    int res[MAX];
    memset(res, -1, sizeof(res));
    int previous = 0;
    present[v[0]]=true;
    for(int i=1; i<n; ++i){
	    if(v[i] != v[i-1]){
		    res[i] = v[i-1];
	    	    present[res[i]]=true;
	    }
    }
    int m = 0;
    present[v[n-1]]=true;
    for(int i=0; i<n; ++i){
	    while(present[m])
		    m++;
	    if(res[i] == -1){
		    res[i]=m;
		    present[m]=true;
	    }
    }
    for(int i=0; i<n; ++i)
	    cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
