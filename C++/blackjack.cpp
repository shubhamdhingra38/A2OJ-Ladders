#include<bits/stdc++.h>
#define REP(n) for(int i=0; i<n; ++i)
#define append push_back
#define ulli unsigned long long int
#define li long int
#define lli long long int
#define endl "\n"
#ifndef ONLINE_JUDGE
#define whats(x) cout<<#x<<" is "<<x<<endl;
#else
#define whats(x)
#endif

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int req = n-10;
    if(req == 10){
        cout<<15<<endl;
    }
    else if(req == 1){
        cout<<4<<endl;
    }
    else if(req < 10 && req >= 1){
        cout<<4<<endl;
    }
    else if(req == 11){
        cout<<4<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}