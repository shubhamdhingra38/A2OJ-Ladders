#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
using namespace std;
typedef long long int lli;
#define MAX 10000005
// 3 1 3
// 2

// 3 1 1 5
// 2 + 2 = 4

//3 0 1 2 
// 3 + 2 = 5

//3 0 1 2 5
// 3 + 2 + 1 = 6

//3 0 4 5
// 3

//7 4 0 9
//3 + 7

//6 9 9


//3 0 1 2 3 2 1 5 4
//3 + 2 + 1 + 1 + 2  = 9

//3 0 1 2 3 2 1 5 4 3 2 1 0 1
// 3 + 2 + 1 + 0 + 1 + 2 + 1
int arr[MAX];
pair<int, int> mx[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    for(int i=0; i<n; ++i){
	        cin>>arr[i];
	    }
	    mx[n-1] = {arr[n-1], n-1};
	    int m;
	    for(int i=n-2; i>=0; --i){
	        if(arr[i] > mx[i+1].first){
	            mx[i] = {arr[i], i};
	        }
	        else{
	            mx[i] = mx[i+1];
	        }
	    }
	    pair<int, int> p;
	    int rain = 0;
	    int a, b;
	    int ele;
	    int i = 0;
	    while(i < n-1){
	        a = i;
	        p = mx[i+1];
	        ele = p.first;
	        b = p.second;
	        m = min(arr[i], ele);
	        //DEBUG(i);
	        //DEBUG(b);
	        //DEBUG(m);
	        while(i < b){
				//DEBUG(i);
	            rain += max(0, (m - arr[i]));
	            if(arr[i] > m){
					m = min(arr[i], ele);
				}
                i++;
	        }
	    }
	    cout<<rain<<endl;
	}
    return 0;
}
