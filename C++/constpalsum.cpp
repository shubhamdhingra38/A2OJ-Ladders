#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define endl "\n"
#define MAX 200005
using namespace std;
int main(){
    int t;
    cin>>t;
    int arr[MAX];
    int prefix[2*MAX+50];
    unordered_map<int, int> map;
    vector<pair<int, int> > v;
    while(t--){
        memset(prefix, 0, sizeof(prefix));
        map.clear();
        v.clear();
        int n, k;
        cin>>n>>k;
        for(int i=0; i<n; ++i)
            cin>>arr[i];
        for(int i=0; i<n/2; ++i)
            v.push_back(make_pair(min(arr[i], arr[n-i-1]), max(arr[i], arr[n-i-1])));
        for(int i=0; i<n/2; ++i)
            map[v[i].first + v[i].second]++;
        for(int i=0; i<n/2; ++i){
            int lower = v[i].first + 1;
            int upper = v[i].second + k;
            prefix[lower] += 1;
            prefix[upper + 1] -= 1;
        }
        int sum = 0;
        for(int i=2; i<=2*k+1; ++i){
           sum += prefix[i];
           prefix[i] = sum;
        }

        int minimum_changes = INT_MAX;
        for(int i=2; i<=2*k; ++i){
            int cnt0 = map[i];
            // DEBUG(cnt0);
            int cnt1 = prefix[i]-cnt0;
            int cnt2 = (n/2)-prefix[i];
            // DEBUG(cnt2);

            int cost = cnt1 + 2 * cnt2;
            minimum_changes = min(minimum_changes, cost);
        }
        cout<<minimum_changes<<endl;
    }
    return 0;
}