#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
    unordered_map<int, int> where;
    int n, m;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin>>arr[i];
        where[arr[i]] = i;
    }
    cin>>m;
    int queries[m];
    for(int i=0; i<m; ++i){
        cin>>queries[i];
    }
    int ele;
    lli first, second;
    first = second = 0;
    for(int i=0; i<m; ++i){
        ele = queries[i];
        first += where[ele] + 1;
        second += n - where[ele];
    }
    cout<<first<<" "<<second<<endl;
    return 0;
}