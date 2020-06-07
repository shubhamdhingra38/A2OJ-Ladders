#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 200005
using namespace std;
typedef pair<int, int> pi;

struct Comparator { 
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) { 
        if(p1.first == p2.first)
        return p1.second > p2.second;
            return p1.first < p2.first;
    } 
}; 

int main(){

    int t, n;
    vector<int> arr(MAX);
    cin>>t;
    while(t--){
        priority_queue<pi, vector<pi>, Comparator> heap;
        cin>>n;
        int cnt = 0;
        heap.push({n, 0});
        while(cnt < n){
            cnt++;
            pair<int, int> p = heap.top();
            heap.pop();
            // DEBUG(p.first);
            // DEBUG(p.second);
            int index = p.second + (p.first-1)/2;
            // DEBUG(index);
            arr[index] = cnt;
            if(index != p.second)
                heap.push({(p.first-1)/2, p.second});
            if(index+1<n)
                heap.push({p.first/2, index+1});

        }
        for(int i=0; i<n; ++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}