#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 50
using namespace std;
int mat[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n, m;
    cin>>t;
    while(t--){
		cin>>n>>m;
		vector<int> zeros(m+n, 0);
		vector<int> ones(m+n, 0);
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				int x;
				cin>>x;
				if(x==0) zeros[i+j]++;
				else ones[i+j]++;
				mat[i][j] = x;
			}
		}
		int result = 0;
		for(int i=0; i<=(m+n-2)/2; ++i){
			if(i==(m+n-2)/2 && (m+n)%2==0) continue;
			result += min(zeros[i]+zeros[n+m-2-i], ones[i]+ones[n+m-2-i]);
		}
		cout<<result<<endl;
		
	}
    return 0;
}
