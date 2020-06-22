#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
	    string s;
	    cin>>s;
	    vector<char> res;
	    for(int i=0; i<s.size(); i+=2){
		    res.push_back(s[i]);
	    }
	    if(s.size()%2 == 0)
		    res.push_back(s[s.size()-1]);
	    for(char& ch: res)
		    cout<<ch;
	    cout<<endl;
    }
    return 0;
}
