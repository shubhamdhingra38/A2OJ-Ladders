#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 60
using namespace std;
typedef long long int lli;
char mat[MAX][MAX];
bool visited[MAX][MAX];
void dfs(int i, int j, int n){
	if(i < 0 || i >= n || j < 0 || j >= n)
		return;
	if(visited[i][j])
		return;
	visited[i][j] = true;
	if((i >= 1 && i < n-1) && (j >= 1 && j < n-1)){
		if(mat[i][j] == '.' && mat[i+1][j] == '.' && mat[i-1][j] == '.' && mat[i][j+1] == '.' && mat[i][j-1] == '.'){		
			mat[i][j] = '#';
			mat[i+1][j] = '#';
			mat[i-1][j] = '#';
			mat[i][j+1] = '#';
			mat[i][j-1] = '#';
		}
	}
	dfs(i+1, j, n);
	dfs(i-1, j, n);
	dfs(i, j+1, n);
	dfs(i, j-1, n); 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		char ch;
		for(int j=0; j<n; ++j){
			visited[i][j] = false;
			cin>>ch;
			mat[i][j] = ch;
		}
	}
	dfs(0, 0, n);
	bool flag = true;
	for(int i=0; i<n; ++i){
		if(!flag) break;
		for(int j=0; j<n; ++j){
			if(mat[i][j] == '.'){
				flag = false;
				break;
			}
		}
	}
	if(flag) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    return 0;
}
