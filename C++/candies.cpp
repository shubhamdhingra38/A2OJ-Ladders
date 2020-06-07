#include<bits/stdc++.h>
#define endl "\n"
#define popcount __builtin_popcount
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;

bool is_pow_two(int num){
    return popcount(num + 1) == 1;
}

int prime_factorise(int num){
    for(int i=1; i*i<=num; ++i){
        if(num%i==0){
            if(is_pow_two(num/i))
                return i;
            if(is_pow_two(i) && i != 1)
                return num/i;
        }
        
    }
    return -1;
}

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int res = prime_factorise(n);
        cout<<res<<endl;
    }
    return 0;
}