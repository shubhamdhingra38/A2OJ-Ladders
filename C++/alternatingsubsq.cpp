#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 200005
#define endl "\n"
typedef long long int lli;
using namespace std;
int main(){
    int t, n;
    cin>>t;
    int arr[MAX];
    while(t--){
        cin>>n;
        for(int i=0; i<n; ++i)
            cin>>arr[i];
        lli max_possible_sum = 0;
        int prev = arr[0];
        for(int i=1; i<n; ++i){
            if((lli)arr[i]*prev > 0)
                prev = max(prev, arr[i]);
            else{
                max_possible_sum += (lli)prev;
                prev = arr[i];
            }
        }
        max_possible_sum += prev;
        cout<<max_possible_sum<<endl;
    }
    return 0;
}