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


vector<int> num;
lli dp[MAX][MAX][2];

lli go(int pos, int cnt, int flag){
    if(pos>num.size() || cnt>3)
        return 0;
    if(pos==num.size())
        return 1;
    if(dp[pos][cnt][flag]!=-1)
        return dp[pos][cnt][flag];
    else{
        lli res=0;
        int nf, ncnt;
        int limit;
        if(flag)
            limit=9;
        else
            limit=num[pos];
        for(int i=0; i<=limit; ++i){
            nf=flag;
            if(i<limit)
                nf=1;
            ncnt=cnt+(i==0?0:1);
            res+=go(pos+1,ncnt,nf);
        }
        dp[pos][cnt][flag]=res;
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
    return go(0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        lli res = solve(b)-solve(a-1);
        cout<<res<<endl;
    }
    return 0;
}