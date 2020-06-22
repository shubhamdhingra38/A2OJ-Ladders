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
	char ch;
	cin>>ch;
	if(ch >= 97 && ch <= 97 + 26){
		cout<<'a'<<endl;
	}
	else
		cout<<'A'<<endl;
    return 0;
}
