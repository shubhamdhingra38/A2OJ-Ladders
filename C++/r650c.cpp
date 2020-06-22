#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 200005
using namespace std;
int get_vacant(int x, int y, int k){
	int res = 0;
	for(int i=x; i<y; i+=k+1)
		res++;
	return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
	    int n, k;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	    //DEBUG(s);
	    vector<int> pos_one;
	    for(int i=0; i<s.size(); ++i){
		    if(s[i] == '1')
			    pos_one.push_back(i);
	    }
	    //DEBUG(pos_one.size());
	    int cnt = 0;
	    if(pos_one.size() >= 2){
	    	for(int i=1; i<pos_one.size(); ++i){
	    		int diff = pos_one[i] - pos_one[i-1] - 1;
	    	    //DEBUG(diff);
	    	    if(diff > 2*k){
	    	    	diff -= 2*k;
	    	    	cnt += max(1, get_vacant(0, diff, k));;
	    	    }
	    	}
	    }
	    if(pos_one.size() >= 1){
	    	int diff_first = pos_one[0];
	    	if(diff_first > k){
	    	        diff_first -= k;
	    	        cnt += max(1, get_vacant(0, diff_first, k));
	    	}
	    	int diff_last = n - pos_one[pos_one.size()-1] - 1;
	    	if(diff_last > k){
	    	        diff_last -= k;
	    	        cnt += max(1, get_vacant(0, diff_last, k)); 
	    	}
	    }
	    else{
		    cnt += max(1, get_vacant(0, n, k));
	    }
	    cout<<cnt<<endl;
    }
    return 0;
}
