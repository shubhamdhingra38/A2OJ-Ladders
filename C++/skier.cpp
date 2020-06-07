#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef pair<int, int> pii;

struct pair_hash {
    inline size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    set<pair<pii, pii>> visited;
    while(t--){
        pii p1 = {0, 0};
        visited.clear();
        int time = 0;
        string s;
        cin>>s;
        for(int i=0; i<s.size(); ++i){
            pii p0 = p1;
            if(s[i]=='N')
                p0.first++;
            else if(s[i]=='S')
                p0.first--;
            else if(s[i]=='W')
                p0.second--;
            else
                p0.second++;

            if(visited.count({p0, p1}) || visited.count({p1, p0}))
                time++;
            else
                time += 5;
            visited.insert({p0, p1});
            p1=p0;
        }
        cout<<time<<endl;
    }
    return 0;
}