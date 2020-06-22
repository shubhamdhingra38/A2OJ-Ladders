#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli k, cnt, x;
    x = 0;
    string result = "codeforces";
    cin>>k;
    DEBUG(k);
    lli cnt_arr[10];
    for(int i=0; i<10; ++i)
        cnt_arr[i] = 1;
    if(k > 1){
        while(true){
            cnt_arr[x] += 1;
            x = (x+1)%10;
            cnt = 1;
            for(int i=0; i<10; ++i)
                cnt = cnt * cnt_arr[i];
            if(cnt >= k)
                break;
        }
    }
    DEBUG(cnt);
    string answer = "";
    for(int i=0; i<10; ++i)
        for(int j=0; j<cnt_arr[i]; ++j)
            answer += result[i];
    cout<<answer<<endl;
    return 0;
}
