#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
int main(){
    int t;
    int n;
    cin>>t;
    int left, right;
    while(t--){
        cin>>n;
        n/=2;
        if(n%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        left = right = 0;
        cout<<"YES"<<endl;
        int cnt = 0;
        for(int i=2; cnt<n ; i+=2){
            cnt++;
            cout<<i<<" ";
            left += i;
        }
        cnt = 0;
        for(int i=1; cnt<n-1; i+=2){
            cnt++;
            cout<<i<<" ";
            right += i;
        }
        cout<<left-right<<endl;
    }
    return 0;
}