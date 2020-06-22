#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 5005
typedef long long int lli;
using namespace std;
lli dp[MAX];

lli go(int idx, int n, string& s){
	if(idx >= n)
		return 1LL;
	if(s[idx] == '0')
		return 0LL;
	if(dp[idx] != -1)
		return dp[idx];
	else{
		lli res;
		if(idx != n-1 && s[idx+1] == '0')
			res = go(idx+2, n, s);
		else if(idx != n-1 && ((s[idx]-'0')*10 + (s[idx+1]-'0') <= 26))
			res = go(idx+1, n, s) + go(idx+2, n, s);
		else{
			//cout<<"HERE"<<endl;
			//int x = (s[idx]-'a'+1)*10 + (s[idx+1]-'a'+1);
			//DEBUG(x);
			res = go(idx+1, n, s);

		}
		dp[idx] = res;
		//DEBUG(idx);
		//DEBUG(res);
		return dp[idx];
	}
}

lli num_encodings(string& s){
	memset(dp, -1, sizeof(dp));
	return go(0, s.size(), s);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
	cin>>s;
    while(!(s.size() == 1 && s[0] == '0')){
	    //DEBUG(s);
	    cout<<num_encodings(s)<<endl;
	    cin>>s;
	}
    return 0;
}
