#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
    int n;
    cin>>n;                     
    int arr[n];
    unordered_map<int, int> howMany;
    for(int i=0; i<n; ++i){
        cin>>arr[i];
        howMany[arr[i]] += 1;
    }
    lli res, maxDiff;
    res = 0;
    int mx, mn;
    mx = *max_element(arr, arr+n);
    mn = *min_element(arr, arr+n);
    if(mx == mn){
        cout<<0<<" "<<((lli)howMany[mx]*((lli)howMany[mx]-1LL))/2<<endl;
    }
    else{
        maxDiff = mx - mn;
        cout<<(lli)maxDiff<<" "<<(lli)howMany[mx]*(lli)howMany[mn];
        cout<<endl;
    }
    return 0;
}