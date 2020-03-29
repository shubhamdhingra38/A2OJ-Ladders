#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x, y, z;
    x = y = z = 0;
    int a, b, c;
    for(int i=0; i<n; ++i){
        cin>>a;
        x+=a;
        cin>>b;
        y+=b;
        cin>>c;
        z+=c;
    }
    if(x == y && y == z && z == 0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}