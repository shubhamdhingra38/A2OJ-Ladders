#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
bool possible(int idx, vector<int>& v, int till, vector<int>& b){
	int res = 0;
	for(int i=0; i<till; ++i)
		res += abs(v[i] - idx);
	return b[idx-1] == res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int x;
    cin>>t;
    while(t--){
	    string s;
	    cin>>s;
	    int n;
	    cin>>n;
	    vector<int> v;
	    vector<char> chars;
	    for(int i=0; i<s.size(); ++i)
		    chars.push_back(s[i]);
	    sort(chars.begin(), chars.end());
	    for(int i=0; i<n; ++i){
		    cin>>x;
		    v.push_back(x);
	    }
	    vector<int> greater;
	    vector<char> res(n);
	    for(int i=0; i<n; ++i)
		    res[i] = '-';
	    int cnt = 0;
	    for(int i=0; i<n; ++i){
		    if(v[i] == 0){
			    res[i] = chars[chars.size()-1];
			    cnt++;
			    greater.push_back(i+1);
		    }
	    }
	    char prev = '-';
	    int d = cnt;
	    for(int i=chars.size()-cnt-1; i>=0; --i){
		    if(cnt == n)
			    break;
		    char ch = chars[i];
		    DEBUG(ch);
		    if(prev != ch)
			    d = cnt;
		    prev = ch;
		    for(int j=1; j<=n; ++j){
			    if(res[j-1] == '-' && possible(j, greater, d, v)){
				    res[j-1] = ch;
				    greater.push_back(j);
				    cnt++;
				    break;
			    }
		    }
	    }
	    for(int i=0; i<n; ++i)
		    cout<<res[i];
	    cout<<endl;

    }
    return 0;
}
