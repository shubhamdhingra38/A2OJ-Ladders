#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int, int> difference;
    unordered_map<int, int> last;
    set<int> elements;
    for(int i=0; i<n; ++i){
        cin>>arr[i];
        last[arr[i]] = -1;
        elements.insert(arr[i]);
    }
    for(int i=0; i<n; ++i){
        if(difference[arr[i]] >= 0){
            if(difference[arr[i]] == 0){
                if(last[arr[i]] == -1)
                   last[arr[i]] = i;
                 else{
                    difference[arr[i]] = i - last[arr[i]];
                    last[arr[i]] = i;
                }
            }
            else{
                if(i-last[arr[i]] == difference[arr[i]]){
                    last[arr[i]] = i;
                }
                else{
                    difference[arr[i]] = -1;
                }
            }
        }
    }
    int cnt = 0;
    for(auto it: difference){
        if(it.second != -1)
            cnt++;
    }
    cout<<cnt<<endl;
    for(auto it: elements){
        if(difference[it] != -1){
            cout<<it<<" "<<difference[it]<<endl;
        }
    }
    return 0;
}