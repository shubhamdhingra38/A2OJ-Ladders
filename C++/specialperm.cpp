#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl; 
#endif
#define MAX 1005
using namespace std;
int n;
bool visited[MAX];
vector<int> graph[MAX];
vector<int> path;
void dfs(int u){
	visited[u]=true;
	path.push_back(u);
	for(int neighbor: graph[u]){
		if(!visited[neighbor]){
			dfs(neighbor);
			break;
		}
	}
}
void add_edge(int a, int b){
	if(a>0&&b>0&&a<=n&&b<=n){
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; ++i){
			graph[i].clear();
			visited[i]=false;
		}
		for(int i=1; i<=n; ++i){
			for(int j=2; j<=4; ++j){
				add_edge(i,i+j);
				add_edge(i,i-j);
			}
		}
		bool f=false;
		for(int i=1; i<=n; ++i){
			path.clear();
			for(int j=1; j<=n; ++j)
				visited[j]=false;
			dfs(i);
			if(path.size()==n){
				f=true;
				break;
			}
		}
		if(f){
			for(auto&x:path)
				cout<<x<<" ";
			cout<<endl;
		}
		else
			cout<<-1<<endl;
		
	}
    return 0;
}
