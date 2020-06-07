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
    int t, x, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> arr(n);
        vector<int> freq(n+1);
        for(int i=0; i<n; ++i){
            cin>>x;
            arr[i] = x;
            freq[arr[i]]++;
        }
        int result = 0;
        for(int i=0; i<n; ++i){
            int sum = 0;
            for(int j=i; j<n; ++j){
                sum += arr[j];
                if(sum<=n && j-i+1 >=2 && freq[sum] != 0){
                    // DEBUG(sum);
                    result += freq[sum];
                    freq[sum] = 0;
                }
            }
        }
        cout<<result<<endl;
    }
    return 0;
}