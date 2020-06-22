#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl;
#endif
using namespace std;
typedef long long int lli;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	vector<char> v;
	while(n > 0){
		if(n%26 == 0){
			v.push_back('z');
			n /= 26;
			n--;
		}
		else{
			v.push_back(97 + (n%26) - 1);
			n /= 26;
		}
	}
	reverse(v.begin(), v.end());
	for(int i=0; i<v.size(); ++i)
		cout<<v[i];
	cout<<endl;
    return 0;
}
