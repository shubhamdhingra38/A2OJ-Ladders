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
    bool f = false;
    int n, x, y;
    cin>>n;
    vector<pair<int, int>> v;
    REP(n){
        cin>>x>>y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    for(int i=1; i<n; ++i){
        if(v[i].second < v[i-1].second){
            f = true;
            break;
        }
    }    
    if(f){
        cout<<"Happy Alex"<<endl;
    }
    else{
        cout<<"Poor Alex"<<endl;
    }
    return 0;
}