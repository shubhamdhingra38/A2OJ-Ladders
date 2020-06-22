#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef lli long long int;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli a, b, n;
        cin>>a>>b>>n;
        lli mx, mn;
        mx = max(a, b);
        mn = min(a, b);
        int cnt = 0;
        while(mx <= n && mn <= n){
           if(cnt%2 == 0)
               mn += mx;
           else
               mx += mn;
           cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
