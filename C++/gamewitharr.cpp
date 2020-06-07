#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
int main(){
    int n, s;
    int x;
    cin>>n>>s;
    vector<int> v(n);
    if(s-(n-1) >= n+1){
        cout<<"YES"<<endl;
        for(int i=0; i<n-1; ++i)
            v[i] = 1;
        v[n-1] = s-(n-1);
        for(int &a: v)
            cout<<a<<" ";
        cout<<"\n"<<n<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}