#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 505
typedef long long int lli;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    lli arr[MAX];
    for(int i=0; i<n; ++i)
        cin>>arr[i];
    lli result = 0;
    if(n == 1)
        cout<<arr[0]<<endl;
    else if(n == 2)
        cout<<(arr[0] | arr[1])<<endl;
    else{
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                for(int k=j+1; k<n; ++k)
                    result = max(result, arr[i]|arr[j]|arr[k]);
            }
        }
        cout<<result<<endl;
    }
    return 0;
}