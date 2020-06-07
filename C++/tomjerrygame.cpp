#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
typedef long long int lli;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    lli tom, jerry;
    cin>>t;
    while(t--){
        cin>>tom;
        if(tom&1)
            cout<<tom/2<<endl;
        else if(__builtin_popcountll(tom) == 1)
            cout<<0<<endl;
        else{
            while(!(tom&1))
                tom = tom>>1;
            tom = tom>>1;
            cout<<tom<<endl;
        }
    }
    return 0;
}
