#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
int main(){
    int t, x, n, p;
    int arr[60][60];
    cin>>t;
    while(t--){
        cin>>n>>p;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cout<<1<<" "<<i+1<<" "<<i+1<<" "<<j+1<<" "<<j+1<<"\n";
                fflush(stdout);
                cin>>x;
                if(x==-1)
                    abort();
                arr[i][j] = x;
            }
        }
        cout<<"2\n";
        fflush(stdout);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
            fflush(stdout);
        }
        cin>>x;
        if(x!=1)
            abort();
    }
    return 0;
}