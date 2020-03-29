#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    int sat = 0;
    cin>>n>>m;
    int arr[n];
    for(int i=0; i<n; ++i)
        cin>>arr[i];
    while(sat != n-1){
        for(int i=0; i<n; ++i){
            if(arr[i] != -1){
                arr[i] = max(0, arr[i]-m);
                if(arr[i] == 0){
                    arr[i] = -1;
                    sat++;
                    if(sat == n-1)
                        break;
                }
            }
        }
    }
    for(int i=0; i<n; ++i){
        if(arr[i] != -1){
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}