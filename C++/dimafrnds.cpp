#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ele;
    int cnt = 0;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>ele;
        cnt += ele;
    }
    int res = 0;
    for(int i=1; i<=5; ++i){
        if((cnt+i)%(n+1)!=1)
            res++;
    }
    cout<<res<<endl;
    return 0;
}
