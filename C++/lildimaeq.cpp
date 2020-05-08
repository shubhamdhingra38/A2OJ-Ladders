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
#define MAX 1000000000
#define lli long long int
using namespace std;
int sumOfDigits(int x){
    int res = 0;
    while(x != 0){
        res += x%10;
        x = x/10;
    }
    res += x/10;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    lli a, b, c;
    lli res;
    lli cnt;
    vector<lli> v;
    cin>>a>>b>>c;
    for(int i=0; i<=81; ++i){
        res = b*pow(i, a)+c;
        if(i == sumOfDigits(res) && res < MAX){
            v.push_back(res);
        }
    }
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}