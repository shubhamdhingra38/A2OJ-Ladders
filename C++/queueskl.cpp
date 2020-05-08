//BGGBG
//GBGGB
//GGBGB
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    cin>>n>>t;
    vector<char> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    for(int i=0; i<t; ++i){
        for(int j=0; j<n-1; ++j){
            if(v[j]=='B' && v[j+1] == 'G'){
                swap(v[j], v[j+1]);
                j += 1;
            }
        }
    }
    for(auto ch: v){
        cout<<ch;
    }
    cout<<endl;
    return 0;
}