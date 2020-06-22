#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
bool inline same_parity(int x, int y){
	int r = x%2;
	return y%2 == r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int x;
    cin>>t;
    while(t--){
	    int n;
	    cin>>n;
	    vector<int> v;
	    int cnt = 0;
	    bool possible = true;
	    for(int i=0; i<n; ++i){
		    cin>>x;
		    v.push_back(x);
	    }
	    for(int i=0; i<n; ++i){
		    if(!same_parity(i, v[i])){
			    bool f = false;
			    for(int j=0; j<n; ++j){
				    if(i == j)
					    continue;
				    if(!same_parity(j, v[j]) && !same_parity(v[i], v[j])){
					    swap(v[j], v[i]);
					    cnt++;
					    f = true;
					    break;
				    }
			    }
			    if(!f){
				    possible = false;
				    break;
			    }
		    }
	    }
	    if(!possible){
		    cout<<-1<<endl;
	    }
	    else{
		    cout<<cnt<<endl;
	    }
    }
    return 0;
}
