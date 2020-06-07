#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    int n0, n1, n2;
    cin>>t;
    while(t--){
        cin>>n0>>n1>>n2;
        if(n0 == 0){
            if(n1 == 0){
                for(int i=0; i<=n2; ++i)
                    cout<<1;
            }
            else if(n2 == 0){
                for(int i=0; i<=n1; ++i){
                    if(i&1)
                        cout<<0;
                    else
                        cout<<1;
                }
            }
            else{
                for(int i=0; i<=n2; ++i)
                    cout<<1;
                for(int i=0; i<n1; ++i){
                    if(i&1)
                        cout<<1;
                    else
                        cout<<0;
                }
            }
        }
        else if(n1 == 0){
            if(n2 == 0){
                for(int i=0; i<=n0; ++i)
                    cout<<0;
            }
        }
        else if(n2 == 0){
            for(int i=0; i<=n0; ++i)
                cout<<0;
            for(int i=0; i<n1; ++i){
                if(i&1)
                    cout<<0;
                else
                    cout<<1;
            }
        }
        else{
            for(int i=0; i<=n2; ++i)
                cout<<1;
            for(int i=0; i<=n0; ++i)
                cout<<0;
            for(int i=0; i<n1-1; ++i){
                if(i&1)
                    cout<<0;
                else
                    cout<<1;
            }
        }
        cout<<endl;
    }
    return 0;
}