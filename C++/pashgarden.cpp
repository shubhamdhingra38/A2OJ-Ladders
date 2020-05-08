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
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1 == x2){
       cout<<x1+abs(y2-y1)<<" "<<y1<<" "<<x1+abs(y2-y1)<<" "<<y2<<endl; 
    }
    else if(y1 == y2){
        cout<<x1<<" "<<y1+abs(x2-x1)<<" "<<x2<<" "<<y1+abs(x2-x1)<<endl;
    }
    else if(abs(x1-x2) == abs(y1-y2)){
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}