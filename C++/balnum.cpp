#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 80
typedef long long int lli;
using namespace std;
lli a, b;

vector<lli> num;
lli dp[MAX][MAX][MAX][2];

lli go(int pos, int o, int e, int flag){
    if(pos>num.size())
        return 0;
    if(pos==num.size()){
        if((e%2 == 1) && (o%2 == 0)){
            cout<<"HERE"<<endl;
            cout<<e<<" and "<<o<<endl;
            return 1;
        }
        return 0;
    }
    if(dp[pos][o][e][flag] != -1)
        return dp[pos][o][e][flag];
    else{
        lli res=0;
        int nf, ncnto, ncnte, limit;
        if(flag)
            limit=9;
        else
            limit=num[pos];
        for(int i=0;i<=limit;++i){
            nf=flag;
            if(i<limit)
                nf=1;
            if(i != 0){
                if(i%2 == 1){
                    ncnto = o+1;
                    ncnte = e;
                }
                else{
                    ncnte = e+1;
                    ncnto = o;
                }
            }
            else{
                ncnto=o;
                ncnte=e;
            }
            DEBUG(i);
            lli x = go(pos+1,ncnto,ncnte,nf);
            DEBUG(x);
            res+=x;
        }
        dp[pos][o][e][flag]=res;
        DEBUG(res);
        return res;
    }
}

lli solve(lli x){
    num.clear();
    while(x){
        num.push_back(x%10);
        x=x/10;
    }
    memset(dp, -1, sizeof(dp));
    reverse(num.begin(),num.end());
    return go(0,0,0,0);
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        DEBUG(b);
        DEBUG(a);
        lli one=solve(b);
        lli two=solve(a-1);
        DEBUG(one);
        DEBUG(two);
        // lli res=solve(b)-solve(a-1);
        cout<<one-two<<endl;
    }
    return 0;
}